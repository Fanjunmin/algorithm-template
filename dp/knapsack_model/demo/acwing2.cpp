#include <iostream>
using namespace std;

const int N = 1010;
int v[N], w[N];
int f[N][N];

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) cin >> v[i] >> w[i];
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << f[m][n];
    return 0;
    
}

/*
//优化版
#include <iostream>
#include <cmath>
using namespace std;

const int K = 1010;
int v[K], w[K];
int f[K];

int main()
{
    int N, V;
    cin >> N >> V;
    for (int i = 1; i <= N; ++i) cin >> v[i] >> w[i];
    for (int i = 1; i <= N; ++i) {
        for (int j = V; j >= 0; --j) {
            if (j >= v[i]) f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[V];
    return 0;
    
}
*/

