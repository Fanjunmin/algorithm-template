#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010, M = 11;
int n, m;
char in[N][M];
char q[M];
int op;
int f[M][M];

int count_dist(char a[], char b[])
{
    int la = strlen(a + 1), lb = strlen(b + 1);
    for (int i = 0; i <= la; ++i) f[i][0] = i;
    for (int i = 0; i <= lb; ++i) f[0][i] = i;
    for (int i = 1; i <= la; ++i) {
        for (int j = 1; j <= lb; ++j) {
            f[i][j] = 1 + min(f[i - 1][j], f[i][j - 1]);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] == b[j] ? 0 : 1));
        }
    }
    return f[la][lb];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%s", in[i] + 1);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%s%d", q + 1, &op);
        int ret = 0;
        for (int j = 0; j < n; ++j) {
            if (count_dist(q, in[j]) <= op) {
                ++ret;
            }
        }
        cout << ret << endl;
    }
    return 0;
}