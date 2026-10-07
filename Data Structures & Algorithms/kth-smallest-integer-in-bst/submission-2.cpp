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
    int kthSmallest(TreeNode* root, int k) {
        //declare min heap of size k
        priority_queue<int> max_heap;
        dfs(root, max_heap, k);

        return max_heap.top();
    }

    void dfs(TreeNode* root, priority_queue<int> &max_heap, int &k) {
        if (!root) return;

        max_heap.push(root->val);
        if (max_heap.size() > k) {
            max_heap.pop();
        }

        dfs(root->right, max_heap, k);
        dfs(root->left, max_heap, k);
    }
};
