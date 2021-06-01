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
    int dfs(TreeNode* root, int pre_sum) {
        if (!root) return 0;
        else if (!root->left && !root->right) return pre_sum * 10 + root->val;
        pre_sum = pre_sum * 10 + root->val;
        return dfs(root->left, pre_sum) + dfs(root->right, pre_sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, 0);
    }
};