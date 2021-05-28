#include <cstring>
const int N = 1e4;
const int INF = 0x3f3f3f3f;
int g[N][N];
int n;

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