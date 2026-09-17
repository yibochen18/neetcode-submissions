class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long max = 0, min = 10000000001;

        for (auto pile : piles) {
            if (pile > max) max = pile;
        }

        //b-search from 1-> max piles cause we know if we eat k we will guarantee eating everything
        bsearch(piles, h, 1, max, min);
        return min;
        
    }

    void bsearch(vector<int> &piles, int h, int l, int r, long long &min) {
        if (l > r) return;

        int m = l + (r - l) / 2;
        int speed = m, time = 0;
        // cout << "curr speed: " << speed << endl;

        for (auto pile: piles) {
            time += ceil(static_cast<double>(pile) / speed);
        }

        // cout << "time taken: " << time << endl;

        if (time <= h && speed < min) min = speed;
        return time > h ? bsearch(piles, h, m + 1, r, min) : bsearch(piles, h, l, m - 1, min);

    }
};
