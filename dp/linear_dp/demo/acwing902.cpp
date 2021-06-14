#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010;
int n, m;
char a[N], b[N];
int f[N][N];

int count_dist(char a[], char b[])
{
    int la = strlen(a + 1), lb = strlen(b + 1);
    for (int i = 0; i <= la; ++i) f[i][0] = i;
    for (int i = 0; i <= lb; ++i) f[0][i] = i;
    for (int i = 1; i <= la; ++i) {
        for (int j = 1; j <= lb; ++j) {
            f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] == b[j] ? 0 : 1));
        }
    }
    return f[la][lb];
}

int main()
{
    scanf("%d%s%d%s", &n, a + 1, &m, b + 1);
    cout << count_dist(a, b);
    return 0;
}