#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
const int M = 2 * N;
int n, m, x, y;
int h[N], d[N], st[N];
int e[M], ne[M], idx;
int q[M], head, tail;
int topo[N];

void init()
{
    head = 0;
    tail = -1;
    memset(h, -1, sizeof(h));
}

void add(int a, int b)
{
    idx++;
    e[idx] = b; ne[idx] = h[a]; h[a] = idx;
}

bool topo_sort()
{
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 0) {
            q[++tail] = i;
        }
    }
    int cnt = 0;
    // bfs
    while (head <= tail) {
        int t = q[head++];
        topo[cnt++] = t;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > 0) --d[j];
            if (d[j] == 0) q[++tail] = j;
        }
    }
    if (cnt == n) return true;
    else return false;
}

int main()
{
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        d[y]++;
        add(x, y);
    }
    if (topo_sort()) {
        for (int i = 0; i < n; ++i) {
            cout << topo[i] << " ";
        }
    } else {
        cout << -1;
    }
    return 0;
}