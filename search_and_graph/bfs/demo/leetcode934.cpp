class Solution {
private:
    static const int N = 10010;
    static constexpr int dx[4] = {0, 0, -1, 1};
    static constexpr int dy[4] = {1, -1, 0, 0};
    int dist[N];
    int len1, len2, n;
    queue<int> q;

    void init() {
        memset(dist, -1, sizeof(dist));
    }

    void dfs(int k, vector<vector<int>>& grid) {
        int x = k / len2, y = k % len2;
        if (grid[x][y] == 0) {
            dist[k] = 0;
            q.push(k);
            return;
        }
        if (grid[x][y] == 1) {
            grid[x][y] = 2;
            for (int i = 0; i < 4; ++i) {
                x += dx[i];
                y += dy[i];
                if (x >= 0 && x < len1 && y >= 0 && y < len2) {
                    dfs(x * len2 + y, grid);
                }
                x -= dx[i];
                y -= dy[i];
            }
        }
    }
    int bfs(vector<vector<int>>& grid) {
        int cnt = 0;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t / len2, y = t % len2;
            int cnt = dist[t], new_idx;
            if (grid[x][y] == 1) {
                return cnt;
            }
            for (int i = 0; i < 4; ++i) {
                x += dx[i];
                y += dy[i];
                new_idx = x * len2 + y;
                if (x >= 0 && x < len1 && y >= 0 && y < len2 &&
                    grid[x][y] != 2 && dist[new_idx] == -1) {
                    dist[new_idx] = 1 + dist[t];
                    q.push(new_idx);
                }
                x -= dx[i];
                y -= dy[i];
            }
        }
        return cnt;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        len1 = grid.size();
        len2 = grid[0].size();
        n = len1 * len2;
        int k = 0;
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                if (grid[i][j] == 1) {
                    k = i * len2 + j;
                    break;
                }
            }
            if (k != 0) break;
        }
        init();
        dfs(k, grid);
        return bfs(grid);
    }
};