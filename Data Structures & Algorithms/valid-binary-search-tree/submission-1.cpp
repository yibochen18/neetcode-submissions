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
    bool isValidBST(TreeNode* root) {
        if (!root) return false;
        bool valid = true;
        dfs(root, INT_MIN, INT_MAX, valid);
        return valid;
    }

    void dfs(TreeNode* root, int low, int high, bool &valid) {
        if (!root) return;

        //current step, check if it fails
        if (root->val <= low || root->val >= high){
            valid = false;
            return;
        }
        
        dfs(root->right, root->val, high, valid);
        dfs(root->left, low, root->val, valid);
    }
};
