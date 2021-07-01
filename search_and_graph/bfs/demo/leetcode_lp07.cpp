class Solution {
private:
    int h[15];
    int e[100], ne[100], idx;
    void init() {
        memset(h, -1, sizeof(h));
        memset(e, 0, sizeof(e));
        memset(ne, 0, sizeof(ne));
        idx = 0;
    }
    void add(int a, int b) {
        idx++;
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx;
    }
    int bfs(int n, int k) {
        queue<pair<int, int>> q;
        int cnt = 0;
        q.push({0, 0});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int index = t.first;
            int time = t.second;
            if (time == k) {
                if (index == n - 1) {
                    cnt++;
                }
                continue;
            }
            for (int i = h[index]; i != -1; i = ne[i]) {
                int j = e[i];
                int j_time = 1 + time;
                q.push({j, j_time});
            }
        }
        return cnt;
    }
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        init();
        for (auto rela : relation) {
            add(rela[0], rela[1]);
        }
        return bfs(n, k);
    }
};