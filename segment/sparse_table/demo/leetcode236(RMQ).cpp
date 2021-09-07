/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static const int N = 100000;
static const int K = 20;
using VPTI = vector<pair<TreeNode *, int>>;
using UMTI = unordered_map<TreeNode *, int>;
class Solution {
private:
    VPTI eulor_seq;
    UMTI visited;

    int F[N][K] = {0};
    int p_idx = -1, q_idx = -1;

    void dfs_get_eulor_seq(TreeNode* root, TreeNode* p, TreeNode* q, int h) {
        eulor_seq.push_back({root, h});
        visited[root] = 1;
        if (root == p && p_idx == -1) p_idx = eulor_seq.size() - 1;
        if (root == q && q_idx == -1) q_idx = eulor_seq.size() - 1;
        if (root->left && !visited[root->left]) {
            dfs_get_eulor_seq(root->left, p, q, h + 1);
            eulor_seq.push_back({root, h});
        }
        if (root->right && !visited[root->right]) {
            dfs_get_eulor_seq(root->right, p, q, h + 1);
            eulor_seq.push_back({root, h});
        }
    }

    void ST_create() {
        int len = eulor_seq.size();
        int k = log2(len);
        for (int i = 0; i < len; ++i) F[i][0] = i;
        for (int j = 1; j <= k; ++j) {
            for (int i = 0; i + (1 << j) - 1 < len; ++i) {
                if (eulor_seq[F[i][j - 1]].second <= eulor_seq[F[i + (1 << (j - 1))][j - 1]].second)
                    F[i][j] = F[i][j - 1];
                else
                    F[i][j] = F[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    int RMQ_query(int l, int r) {
        int k = log2(r + 1 - l);
        if (eulor_seq[F[l][k]].second <= eulor_seq[F[r - (1 << k) + 1][k]].second)
            return F[l][k];
        else
            return F[r - (1 << k) + 1][k];
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs_get_eulor_seq(root, p, q, 0);
        ST_create();
        if (p_idx > q_idx) swap(p_idx, q_idx);
        int idx = RMQ_query(p_idx, q_idx);
        return eulor_seq[idx].first;
    }
};