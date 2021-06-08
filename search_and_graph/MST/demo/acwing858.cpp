#include <bits/stdc++.h>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int n, m, u, v, w;
int dist[N];
int g[N][N];
int st[N];

int prime()
{
    int res = 0;
    memset(dist, 0x3f, sizeof(dist));
    memset(st, 0, sizeof(st));

    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j) {
            if (st[j] == 0 && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
        if (i && dist[t] == INF) return INF;   //说明有不连通的点, 因此不存在最小的生成树
        if (i) res += dist[t];  //将最小的距离加入生成树
        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[j], g[t][j]);  //更新距离
        }
        st[t] = 1;
    }
    return res;
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= n; ++i) g[i][i] = 0;
    while (m--) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    int t = prime();
    if (t == INF) cout << "impossible";
    else cout << t;
    return 0;
}