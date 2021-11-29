#include <iostream>
using namespace std;

const int N = 1010;
int ser[N];
int dp[N];

int main()
{
    int n, max_num = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> ser[i];
    for (int i = 1; i <= n; ++i) {
        dp[i] = ser[i];
        for (int j = 1; j < i; ++j) {
            if (ser[j] < ser[i]) {
                dp[i] = max(dp[i], ser[i] + dp[j]);
            }
        }
        max_num = max(max_num, dp[i]);
    }
    cout << max_num;
    return 0;
}