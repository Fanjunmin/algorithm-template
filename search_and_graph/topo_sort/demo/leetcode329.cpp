class Solution {
private:
    static const int N = 4e4 + 10, M  = 8e4 + 10;
    static constexpr int dx[2] = {0, -1};
    static constexpr int dy[2] = {-1, 0};
    int n;
    //dp
    int dp[N];
    //edge
    int h[N], d[N];
    int e[M], ne[M], idx;
    //queue
    int q[N], head, tail;

    void init() {
        memset(h, -1, sizeof(h));
        memset(d, 0, sizeof(d));
        memset(dp, 0, sizeof(dp));
        idx = 0;
        head = 0;
        tail = -1;
    }

    void add(int a, int b) {
        idx++;
        e[idx] = b, ne[idx] = h[a], h[a] = idx;
    }

    int topo_sort() {
        int max_cnt = 1;
        for (int i = 0; i < n; ++i) {
            if (d[i] == 0) {
                q[++tail] = i;
                dp[i] = 1;
            }
        }
        while (head <= tail) {
            auto t = q[head++];
            for (int i = h[t]; i != -1; i = ne[i]) {
                int j = e[i];
                if (d[j] > 0) {
                    d[j]--;
                    dp[j] = max(dp[j], 1 + dp[t]);
                    max_cnt = max(max_cnt, dp[j]);
                }
                if (d[j] == 0) {
                    q[++tail] = j;
                }
            }
        }
        return max_cnt;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int len1 = matrix.size();
        int len2 = matrix[0].size();
        n = len1 * len2;
        int x, y;
        init();
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    x = i + dx[k];
                    y = j + dy[k];
                    if (x >= 0 && x < len1 && y >= 0 && y < len2) {
                        if (matrix[i][j] > matrix[x][y]) {
                            add(i * len2 + j, x * len2 + y);
                            d[x * len2 + y]++;
                        } else if (matrix[i][j] < matrix[x][y]) {
                            add(x * len2 + y, i * len2 + j);
                            d[i * len2 + j]++;
                        }
                    }
                }
            }
        }
        return topo_sort();
    }
};