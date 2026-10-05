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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiam = 0;
        //diameter is the sum of the left + right subtree heights
        height(root, maxDiam);
        return maxDiam;
    }

    int height(TreeNode* root, int &maxDiam) {
        if (!root) return 0;
        int leftHeight = height(root->left, maxDiam);
        int rightHeight = height(root->right, maxDiam);

        maxDiam = max(maxDiam, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
};
