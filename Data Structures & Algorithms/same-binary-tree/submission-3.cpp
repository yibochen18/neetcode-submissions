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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        bool valid = true;
        dfs(p, q, valid);
        
        return valid;
    }

    void dfs(TreeNode* p1, TreeNode* q1, bool &valid) {
        if (!p1 && !q1) return;
        if (!p1 || !q1) {
            valid = false;
            return;
        }

        if (p1->val != q1->val) {
            valid = false;
            return;
        }

        dfs(p1->left, q1->left, valid);
        dfs(p1->right, q1->right, valid);
    }
};
