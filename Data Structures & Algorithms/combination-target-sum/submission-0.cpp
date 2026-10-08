class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, cur, target, nums, 0);

        return ans;
    }

    //unique combinations, backtracking
    void dfs(vector<vector<int>> &ans, vector<int> &cur, int remainder, vector<int> &nums, int start) {
        //base case
        if (remainder == 0) {
            ans.push_back(cur);
            return;
        }

        //SANDWICH
        for (int i = start; i < nums.size(); i++) {
            //can choose to reuse, not use, or go to next number
            if (nums[i] > remainder) continue; //invalid number, overshoots
            cur.push_back(nums[i]);

            dfs(ans, cur, remainder - nums[i], nums, i);

            cur.pop_back();
        }

        return;
    }
};
