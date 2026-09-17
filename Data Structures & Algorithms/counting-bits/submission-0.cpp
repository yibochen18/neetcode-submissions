class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            //while its not 0
            int num = i;
            while (num != 0) {
                num &= (num - 1); //clear the lowest set bit
                ans[i]++;
            }
        }

        return ans;
    }
};
