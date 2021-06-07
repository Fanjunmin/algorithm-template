#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int M = 10010;
int dist[N], bk[N]; 
int n, m, k;
struct edge{
    int a;
    int b;
    int w;
} edg[M];

int bellman_ford()
{
    int a, b, w;
    dist[1] = 0;
    for (int i = 0; i < k; ++i) {   //k次松弛操作
        memcpy(bk, dist, sizeof(bk));   //back_up
        for (int j = 0; j < m; ++j) {
            a = edg[j].a, b = edg[j].b, w = edg[j].w;
            dist[b] = min(dist[b], bk[a] + w);
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}

int main()
{
    int x, y, z;
    memset(dist, 0x3f, sizeof(dist));
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> z;
        edg[i] = {x, y, z};
    }
    int ret = bellman_ford();
    if (ret == -1) cout << "impossible";
    else cout << ret;
    return 0;
}