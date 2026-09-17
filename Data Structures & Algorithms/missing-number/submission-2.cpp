class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //can use XOR property
        //number XOR with itself cancels out
        //XOR nums with [0,...,n], everything but missing number will cancel out
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }

        for (int i = 0; i < nums.size() + 1; i++) {
            ans ^= i;
        }

        return ans;
    }
};
