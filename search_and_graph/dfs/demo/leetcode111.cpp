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
private:
    int dfs(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (!root->left) return 1 + dfs(root->right);
        if (!root->right) return 1 + dfs(root->left);
        return 1 + min(dfs(root->left), dfs(root->right));
    }
public:
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};