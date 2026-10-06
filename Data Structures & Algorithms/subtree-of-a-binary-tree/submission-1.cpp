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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //base case
        if (!root || !subRoot) return false;
        //current node
        if (isSameTree(root, subRoot)) return true;
        //recursive step
        return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
    }

    bool isSameTree(TreeNode* root, TreeNode* root2) {
        // base case
        if (!root && !root2) return true;
        if (!root || ! root2 || root->val != root2->val) return false;
        //Trust the recursion
        return isSameTree(root->left, root2->left) && isSameTree(root->right, root2->right);
    }
};
