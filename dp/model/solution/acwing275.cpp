#include <iostream>
using namespace std;
const int N = 60;
int w[N][N];
int dp[2 * N][N][N];
int dx[4] = {-1, -1, 0, 0};
int dy[4] = {-1, 0, -1, 0};
int n, m;
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> w[i][j];
        }
    }
    for (int k = 2; k <= n + m; ++k) {
        for (int i1 = 1; i1 <= m; ++i1) {
            for (int i2 = 1; i2 <= m; ++i2) {
                int j1 = k - i1, j2 = k - i2;
                int &x = dp[k][i1][i2];
                int value = w[i1][j1];
                if (j1 != j2) value += w[i2][j2];
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) {
                    for (int j = 0; j < 4; ++j) {
                        x = max(x, dp[k - 1][i1 + dx[j]][i2 + dy[j]] + value);
                    }
                }
            }
        }
    }
    cout << dp[m + n][m][m];
    return 0;
}