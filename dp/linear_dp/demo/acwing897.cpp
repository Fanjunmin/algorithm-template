#include <iostream>
using namespace std;

const int N = 1010;
int f[N][N];
int n, m;
char A[N], B[N];

int main()
{
    cin >> n >> m;
    char ch;
    scanf("%s%s", A + 1, B + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (A[i] == B[j]) f[i][j] = max(f[i][j], 1 + f[i - 1][j - 1]);
        }
    }
    cout << f[n][m];
    return 0;
}