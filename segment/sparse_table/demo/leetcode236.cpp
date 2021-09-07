/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    using UTT = unordered_map<TreeNode*, TreeNode*>;
    using UTI = unordered_map<TreeNode*, int>;
    void get_parent_and_height(TreeNode* root, TreeNode* par, UTT &parent, UTI &height, int h) {
        if (!root) return;
        parent[root] = par, height[root] = h;
        get_parent_and_height(root->left, root, parent, height, h + 1);
        get_parent_and_height(root->right, root, parent, height, h + 1);
    }

    TreeNode* _lowestCommonAncestor(TreeNode* p, TreeNode* q, int h_delta, UTT &parent) {
        // height of p - q is h_delta
        while (h_delta--) p = parent[p];
        while (p != q) p = parent[p], q = parent[q];
        return p;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        UTT parent;
        UTI height;
        get_parent_and_height(root, 0, parent, height, 0);
        int h_p = height[p], h_q = height[q];
        if (h_p >= h_q) return _lowestCommonAncestor(p, q, h_p - h_q, parent);
        else return _lowestCommonAncestor(q, p, h_q - h_p, parent);
    }
};
