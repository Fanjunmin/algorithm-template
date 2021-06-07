#include <bits/stdc++.h>
using namespace std;

const int N = 210;
int n, m, k;
int g[N][N];
int INF = 0x3f3f3f3f;

void init()
{
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= n; ++i) g[i][i] = 0;
}

void floyd()
{
    int i, j, k;
    for (k = 1; k <= n; ++k)
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= n; ++j)
                g[i][j] = g[i][j] > g[i][k] + g[k][j] ? g[i][k] + g[k][j] : g[i][j];
}

void add(int i, int j, int w)
{
    g[i][j] = g[i][j] > w ? w : g[i][j];
}

bool judge(int i, int j)
{
    return g[i][j] > INF / 2;
}

int main()
{
    int x, y, z;
    cin >> n >> m >> k;
    init();
    while (m--) {
        cin >> x >> y >> z;
        add(x, y, z);
    }
    floyd();
    while (k--) {
        cin >> x >> y;
        if (judge(x, y)) cout << "impossible" << endl;
        else cout << g[x][y] << endl;
    }
    return 0;
}