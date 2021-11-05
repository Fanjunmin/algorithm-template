#include <iostream>
using namespace std;

const int N = 12;
int dp[2*N][N][N];
int w[N][N];
int x[4] = {-1, -1, 0, 0};
int y[4] = {-1, 0, -1, 0};

int main()
{
    int n, r, c, num;
    cin >> n;
    while (cin >> r >> c >> num, r || c || num) w[r][c] = num;
    for (int k = 2; k <= 2 * n; ++k) {
        for (int i1 = 1; i1 <= n; ++i1) {
            for (int i2 = 1; i2 <= n; ++i2) {
                int wt = 0, j1 = k - i1, j2 = k - i2;
                int &temp = dp[k][i1][i2];
                if (i1 == i2) wt = w[i1][j1];
                else wt = w[i1][j1] + w[i2][j2];
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) {
                    for (int j = 0; j < 4; ++j) {
                        temp = max(temp, dp[k - 1][i1 + x[j]][i2 + y[j]] + wt);
                    }
                }
            }
        }
    }
    cout << dp[2 * n][n][n];
    return 0;
}