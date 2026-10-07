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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // just walk down the tree and check
        if (!root || !p || !q) return nullptr;

        while (root) {
            if (p->val > root->val && q->val > root->val) {
                //sits in the right subtree
                root = root->right;
            }
            else if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            else {
                //one is greater and one is less, splits at this level, must be the lca node
                return root;
            }
        }

        return nullptr;
    }
};
