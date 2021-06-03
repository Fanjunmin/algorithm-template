class Solution {
private:
    const static int N = 1e5 + 10, M = 1e5 + 10;
    int h[N], d[N];
    int e[M], ne[M], idx;
    int topo[N];
    int n;
    int q[N], head, tail;
    int f[N][26];   //f[i][k]表示以节点i尾节点的路径中颜色为k的节点的个数
    int max_color;
    void init() {
        memset(h, -1, sizeof(h));
        memset(d, 0, sizeof(d));
        memset(f, 0, sizeof(f));
        idx = 0;
        max_color = 1;
    }
    void add(int a, int b) {
        idx++;
        e[idx] = b; ne[idx] = h[a]; h[a] = idx;
    }
    bool topo_sort(const string &colors) {
        int cnt = 0;
        head = 0; 
        tail = -1;
        for (int i = 0; i < n; ++i) {
            if (d[i] == 0) {
                q[++tail] = i;
                f[i][colors[i] - 'a'] = 1;
            }
        }
        while (head <= tail) {
            int t = q[head++];
            topo[cnt++] = t;
            for (int i = h[t]; i != -1; i = ne[i]) {
                int j = e[i];
                if (d[j] > 0) {
                    --d[j];
                    for (int k = 0; k < 26; ++k) {
                        if (k == colors[j] - 'a') f[j][k] = max(f[j][k], f[t][k] + 1);
                        else f[j][k] = max(f[j][k], f[t][k]);
                        max_color = max(f[j][k], max_color);
                    }
                }
                if (d[j] == 0) q[++tail] = j;
            }
        }
        return cnt == n;    // 拓扑排序判断是否存在环
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        init();
        for (auto edge : edges) {
            if (edge[0] == edge[1]) return -1;
            add(edge[0], edge[1]);
            d[edge[1]]++;
        }
        n = colors.size();
        if (!topo_sort(colors)) return -1;
        return max_color;
    }
};