#include <iostream>
using namespace std;
const int N = 1010;
int a[N], f[N];

int main()
{
    int n;
    int max_cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        f[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[i] > a[j]) f[i] = max(f[i], 1 + f[j]);
        }
        max_cnt = max(max_cnt, f[i]);
    }
    cout << max_cnt;
    return 0;
}