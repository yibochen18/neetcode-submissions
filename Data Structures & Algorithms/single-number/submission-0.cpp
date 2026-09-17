class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // to get ideal just need to xor everything
        int res = 0;

        for (int num: nums) {
            res ^= num;
        }

        return res;
    }
};
