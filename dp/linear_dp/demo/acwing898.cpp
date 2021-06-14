#include <iostream>
using namespace std;
const int N = 510;
int n;
int a[N][N];
int main()
{
    cin >> n;
    int max_sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> a[i][j];
        }
    }
    int t;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                t = a[i - 1][j];
            } else if (i == j) {
                t = a[i - 1][j - 1];
            } else {
                t = max(a[i - 1][j], a[i - 1][j - 1]);
            }
            a[i][j] += t;
        }
    }
    for (int j = 0; j < n; ++j) {
        max_sum = max(max_sum, a[n - 1][j]);
    }
    cout << max_sum;
    return 0;
}