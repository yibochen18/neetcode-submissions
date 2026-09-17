class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> seen(nums.size() + 1, 0);

        for (int num : nums) {
            seen[num] = 1;
        }

        for (int i = 0; i < nums.size() + 1; i++) {
            if (seen[i] == 0) return i;
        }

        //we should never get here
        return -1;
    }
};
