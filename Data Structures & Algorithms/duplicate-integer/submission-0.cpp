class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> ans;

        for (int num : nums)
        {
            if (!(ans.insert(num).second))
            {
                return true;
            }
        }
        return false;
    }
};
