class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        unordered_set<int> used;
        dfs(ans, nums, cur, used);
        return ans;
    }

    //all possible, backtracking
    void dfs(vector<vector<int>> &ans, vector<int> &nums, vector<int> cur, unordered_set<int> used) {
        //base case
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }

        //SANDWICH
        for (int i = 0; i < nums.size(); i++) {
            if (!used.insert(nums[i]).second) {
                //already used
                continue;
            }
            cur.push_back(nums[i]);

            dfs(ans, nums, cur, used);

            cur.pop_back();
            //need to undo the used as well
            used.erase(nums[i]);
        }

        return;
    }
};
