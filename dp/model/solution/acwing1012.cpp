#include <iostream>
#include <algorithm>
using namespace std;
using PII = pair<int, int>;  
const int N = 5010;
PII a[N];
int f[N];

int main()
{
    int n, max_cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    for (int i = 1; i <= n; ++i) {
        f[i] = 1;
        for(int j = 1; j < i; ++j) {
            if (a[i - 1].second > a[j - 1].second) {
                f[i] = max(f[i], 1 + f[j]);
            }
        }
        max_cnt = max(max_cnt, f[i]);
    }
    cout << max_cnt;
    return 0;
}