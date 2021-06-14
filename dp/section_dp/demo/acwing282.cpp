#include <iostream>
using namespace std;
const int N = 310, MAX_W = 3e6;
int w[N], pre_sum[N];
int f[N][N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        pre_sum[i] = pre_sum[i - 1] + w[i];
    }
    
    for (int k = 2; k <= n; ++k) {  //区间长度遍历, 长度为1不需要代价
        for (int i = 1; i + k - 1 <= n; ++i) {
            int l = i, r = i + k - 1;
            int t = pre_sum[r] - pre_sum[l - 1];
            f[l][r] = MAX_W;
            for (int j = l; j < r; ++j) {
                f[l][r] = min(f[l][r], f[l][j] + f[j + 1][r] + t);
            }
        }
    }
    cout << f[1][n];
    return 0;
}