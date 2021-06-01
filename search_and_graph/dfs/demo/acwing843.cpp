#include <iostream>
using namespace std;

const int N = 10, M = 20;
char ch[N][N];
int col[M];     //每一列
int diag[M];    //每一个对角线
int anti_diag[M];   //每一个斜对角线
int n;

void dfs(int u)
{
    if (u == n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ch[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    for (int i = 0; i < n; ++i) {
        if (!col[i] && !diag[u + i] && !anti_diag[i - u + n]) {
            ch[u][i] = 'Q';
            col[i] = diag[u + i] = anti_diag[i - u + n] = 1;
            dfs(u + 1);
            ch[u][i] = '.';
            col[i] = diag[u + i] = anti_diag[i - u + n] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ch[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}