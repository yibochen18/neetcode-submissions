class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto max = *max_element(piles.begin(), piles.end());
        int ans;

        if (piles.size() == h)
        {
            return max;
        }

        int l = 1, r = max;

        while (l <= r)
        {
            int mid = l + (r - l) / 2, totalTime = 0;

            for (int pile : piles)
            {
                totalTime += ceil(static_cast<double>(pile) / mid);
            }

            if (totalTime <= h)
            {
                //its valid but we could have a more optimal one
                ans = mid;
                r = mid - 1;
            }

            if (totalTime > h)
            {
                //need to eat more
                l = mid + 1;
            }
        }

        return ans;
    }
};
