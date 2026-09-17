class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (!ans.insert(nums[i]).second) return true;
        }

        return false;
    }
};