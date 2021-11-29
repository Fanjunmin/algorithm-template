#include <iostream>
using namespace std;

const int N = 1010;
int n;
int h[N], f[N], g[N];

int main()
{
    cin >> n;
    int max1 = 0;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 1; i <= n; ++i) {
        f[i] = 1;
        for (int j = 1; j <= i; ++j) {
            if (h[j] < h[i]) {
                f[i] = max(f[i], 1 + f[j]);
            }
        }
    }
    for (int i = n; i > 0; --i) {
        g[i] = 1;
        for (int j = n; j >= i; --j) {
            if (h[j] < h[i]) {
                g[i] = max(g[i], 1 + g[j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) max1 = max(max1, f[i] + g[i] - 1);
    cout << max1;
    return 0;
}