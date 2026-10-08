class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, 0, cur, nums);

        return ans;
    }

    void dfs(vector<vector<int>> &ans, int start, vector<int> &cur, vector<int> &nums) {
        // subset so every cur is a valid answer
        ans.push_back(cur);

        for (int i = start; i < nums.size(); i++) {
            cur.push_back(nums[i]);


            //recurse!
            dfs(ans, i + 1, cur, nums);

            //undo the sandwich
            cur.pop_back();
        }

        return;
    }
};
