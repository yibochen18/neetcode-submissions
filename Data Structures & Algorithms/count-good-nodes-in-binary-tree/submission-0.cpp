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
        bfs(root, ans);

        return ans;
    }

    //bfs, pass path down
    void bfs(TreeNode* root, int &ans) {
        // pass down maxVal which is the maximum value seen on that path, if current node val >= maxVal, set maxVal and current node is a good node
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while(!q.empty()) {
            auto [node, maxVal] = q.front();
            q.pop();

            if (node->val >= maxVal) {
                ans++;
                maxVal = node->val;
            }

            if (node->left) q.push({node->left, maxVal});
            if (node->right) q.push({node->right, maxVal});
        }

        return;
    }
};
