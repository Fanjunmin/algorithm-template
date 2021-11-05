#include <iostream>
using namespace std;
const int N = 110;
int n;
int p[N][N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p[i][j];
        }
    }
    for (int i = 1; i < n; ++i) {
        p[i][0] += p[i - 1][0];
        p[0][i] += p[0][i - 1]; 
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            p[i][j] += min(p[i - 1][j], p[i][j - 1]);
        }
    }
    cout << p[n - 1][n - 1] << endl;
    return 0;
}