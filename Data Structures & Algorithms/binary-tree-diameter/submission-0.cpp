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
    int global_max = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        //sum of the max depth of its two immediate children = longest path
        if (!root) return 0;

        //get max of left and right leafs
        int diameter = maxDepth(root->left) + maxDepth(root->right);
        if (diameter > global_max) global_max = diameter;

        diameterOfBinaryTree(root->right);
        diameterOfBinaryTree(root->left);

        return global_max;
    }

    int maxDepth(TreeNode* root)
    {
        if (!root) return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
