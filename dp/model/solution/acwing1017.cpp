#include <iostream>
using namespace std;

const int N = 110;
int h[N];
int n, k;
int max_bld;

int get_lcs(int i)
{
    int f[N];
    int max_cnt_l = 0;
    int max_cnt_r = 0;
    for (int j = 1; j <= i; ++j) {
        f[j] = 1;
        for (int x = 1; x <= j; ++x) {
            if (h[x] < h[j]) {
                f[j] = max(f[j], 1 + f[x]);
            }
            max_cnt_l = max(max_cnt_l, f[j]);
        }
    }
    for (int j = i; j <= n; ++j) {
        f[j] = 1;
        for (int x = i; x <= j; ++x) {
            if (h[x] > h[j]) {
                f[j] = max(f[j], 1 + f[x]);
            }
            max_cnt_r = max(max_cnt_r, f[j]);
        }
    }
    return max(max_cnt_l, max_cnt_r);
}

int main()
{
    cin >> k;
    while (k--) {
        cin >> n;
        max_bld = 0;
        for (int i = 1; i <= n; ++i) cin >> h[i];
        for (int i = 1; i <= n; ++i) {
            max_bld = max(max_bld, get_lcs(i));
        }
        cout << max_bld << endl;
    }
    return 0;
}