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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        dfs({root, root->val}, ans);
        return ans;
    }

    void dfs(pair<TreeNode*, int> root, int &ans) {
        if (!root.first) return;
        auto [node, maxVal] = root;
    
        //current node
        if (node->val >= maxVal) {
            maxVal = node->val;
            ans++;
        }

        //recursive step
        dfs({node->right, maxVal}, ans);
        dfs({node->left, maxVal}, ans);
    }
};
