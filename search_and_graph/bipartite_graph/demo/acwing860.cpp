#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 1e5 + 10;
const int M = 2 * N;

int h[N], st[N];
int e[M], ne[M], idx;
int n, m, u, v;

enum {
    COLOR_NONE = 0,
    COLOR_ONE,
    COLOR_TWO,
    COLOR_MAX,
};

void init()
{
    memset(h, -1, sizeof(h));
    idx = 0;
}

void add(int u, int v)
{
    idx++;
    e[idx] = v, ne[idx] = h[u], h[u] = idx;
}

bool bfs(int u)
{
    queue<int> q;
    q.push(u);
    st[u] = COLOR_ONE;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (st[j] == st[t]) return false;
            if (st[j] == COLOR_NONE) {
                st[j] = COLOR_MAX - st[t];
                q.push(j);
            }
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    bool ret = true;
    for (int i = 1; i <= n; ++i) {
        if (st[i] == COLOR_NONE) {
            ret = bfs(i);
            if(!ret) break;
        }
    }
    if (ret) cout << "Yes";
    else cout << "No";
    return 0;
}