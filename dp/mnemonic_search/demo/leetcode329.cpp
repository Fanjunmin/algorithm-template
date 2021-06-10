class Solution {
private:
    int f[210][210];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int r, c;

    void init() {
        memset(f, -1, sizeof(f));
    }

    int dp(int x, int y, const vector<vector<int>>& h) {
        int &t = f[x][y];
        if (t != -1) return t;
        t = 1;
        for (int i = 0; i < 4; ++i) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < r && b >= 0 && b < c && h[a][b] > h[x][y]) {
                t = max(t, 1 + dp(a, b, h));
            }
        }
        return t;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        r = matrix.size();
        c = matrix[0].size();
        init();
        int res = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res = max(res, dp(i, j, matrix));
            }
        }
        return res;
    }
};