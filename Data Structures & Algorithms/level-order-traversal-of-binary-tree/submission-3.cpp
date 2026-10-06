/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        //dfs version
        vector<vector<int>> ans;
        dfs({root, 0}, ans);

        return ans;
    }

    void dfs(pair<TreeNode*, int> root, vector<vector<int>> &ans) {
        auto [node, level] = root;

        if (!node) return;

        if (level == ans.size()) {
            ans.push_back({});
        }

        ans[level].push_back(node->val);

        // recursive step
        dfs({node->left, level + 1}, ans);
        dfs({node->right, level + 1}, ans);
    }
};
