#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, M = 1e5 + 10;
const int MAX_DIST = 0x3f3f3f3f;
int g[N][N];    //邻接矩阵来表示图
int dist[N];
int st[N];
int n, m, x, y, z;

void init()
{
    memset(g, 0x3f, sizeof(g));
    memset(dist, 0x3f, sizeof(dist));
}

int dijkstra()
{
    dist[1] = 0;
    for (int i = 1; i <= n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j) {
            if (st[j] == 0 && (t == -1 || dist[t] >= dist[j])) {
                t = j;
            }
        }
        st[t] = 1;
        for (int j = 1; j <= n; ++j) {
            //更新其他边的距离
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if (dist[n] == MAX_DIST) return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    cout << dijkstra();
    return 0;
}