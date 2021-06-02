#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int path[N][N];
int d[N][N];
int n, m;

PII q[N * N];
int head, tail;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int bfs()
{
    memset(d, -1, sizeof(d));
    head = tail = 0;
    q[0] = {0, 0};
    d[0][0] = 0;
    while (head <= tail) {
        auto t = q[head++];
        for (int i = 0; i < 4; ++i) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && path[x][y] == 0 && d[x][y] == -1) {
                q[++tail] = {x, y};
                d[x][y] = d[t.first][t.second] + 1;
            }
        }
    }
    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> path[i][j];
    cout << bfs();
    return 0;
}