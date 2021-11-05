#include <iostream>
using namespace std;
const int N = 110;
int t, r, c;
int p[N][N];

int main()
{
    cin >> t;
    while (t--) {
        cin >> r >> c; 
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> p[i][j];
            }
        }
        for (int i = 1; i < r; ++i) p[i][0] += p[i - 1][0];
        for (int j = 1; j < c; ++j) p[0][j] += p[0][j - 1]; 
        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                p[i][j] += max(p[i - 1][j], p[i][j - 1]);
            }
        }
        cout << p[r - 1][c - 1] << endl;
    }
    return 0;
}
