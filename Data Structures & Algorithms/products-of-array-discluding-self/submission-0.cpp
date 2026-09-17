class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        bool zero = false, zeros = false;
        for (const int & num : nums)
        {
            if (num != 0)
            {
                product *= num;
            }
            else if (!zero)
            {
                zero = true;
            }
            else zeros = true;
        }

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (zeros || (zero && nums[i] != 0))
            {
                ans.push_back(0);
            }
            else if ((!zero && nums[i] != 0))
            {
                ans.push_back(product / nums[i]);
            }
            else
            {
                ans.push_back(product);
            }
        }

        return ans;
    }
};
