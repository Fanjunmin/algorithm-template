#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int n, m, u, v, w;
int p[N];   //union find

struct edge {
    int u, v, w;
    bool operator<(const edge& e) {
        return w < e.w;
    }
} eg[M];

int find(int a)
{
    return p[a] == a ? a : p[a] = find(p[a]);
}

bool connected(int a, int b)
{
    return find(a) == find(b);
}

void Union(int a, int b)
{
    if (connected(a, b)) return;
    a = find(a), b = find(b);
    p[a] = b;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        eg[i] = {u, v, w};
    }
    sort(eg, eg + m);
    for (int i = 1; i <= n; ++i) p[i] = i;
    int res = 0, cnt = 1;
    for (int i = 0; i < m; ++i) {
        u = eg[i].u, v = eg[i].v, w = eg[i].w;
        if (!connected(u, v)) {
            Union(u, v);
            res += w;
            ++cnt;
        }
    }
    if (cnt < n) cout << "impossible";
    else cout << res;
    return 0;
}