#include <iostream>
using namespace std;

const int N = 1010;
int a[N];
int dp1[N], dp2[N];

int main()
{
    int cnt = 0;
    int max_cnt = 0, gre_cnt = 0;
    while (cin >> a[cnt]) cnt++;
    for (int i = 0; i < cnt; ++i) {
        dp1[i] = dp2[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (a[j] >= a[i]) {
                dp1[i] = max(dp1[i], 1 + dp1[j]);
            } else {
                dp2[i] = max(dp2[i], 1 + dp2[j]);
            }
        }
        max_cnt = max(max_cnt, dp1[i]);
        gre_cnt = max(gre_cnt, dp2[i]);
    }
    cout << max_cnt << endl << gre_cnt << endl;
    return 0;
}