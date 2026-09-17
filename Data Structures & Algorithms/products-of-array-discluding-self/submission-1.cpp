class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //prefix and suffix sum
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());

        prefix[0] = nums[0];
        suffix[nums.size() - 1] = nums[nums.size() - 1];
 
        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i - 1] * nums[i];
        }

        for (int j = nums.size() - 2; j >= 0; j--)
        {
            suffix[j] = suffix[j + 1] * nums[j];
        }

        vector<int> output(nums.size());
        output[0] = suffix[1];
        output[nums.size() - 1] = prefix[nums.size() - 2];

        for (int i = 1; i < nums.size() - 1; i++)
        {
            output[i] = prefix[i - 1] * suffix[i + 1];
        }

        return output;
    }
};
