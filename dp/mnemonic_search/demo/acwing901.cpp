#include <iostream>
#include <cstring>
using namespace std;
const int N = 310;
int r, c;
int h[N][N], f[N][N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void init()
{
    memset(f, -1, sizeof(h));
}

int dp(int x, int y)
{
    int &t = f[x][y];
    if(t != -1) return t;
    t = 1;  //初始为1
    for (int i = 0; i < 4; ++i) {
        int a = x + dx[i], b = y + dy[i];
        if (a > 0 && a <= r && b > 0 && b <= c && h[a][b] < h[x][y]) {
            t = max(t, 1 + dp(a, b));
        }
    }
    return t;
}

int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> h[i][j];
        }
    }
    init();
    int res = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            res = max(res, dp(i, j));
        }
    }
    cout << res;
    return 0;
}