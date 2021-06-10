#include <iostream>
#include <cmath>
using namespace std;

const int MN = 1010;
int v[MN], w[MN];
int f[MN];

int main()
{
    int N, V;
    cin >> N >> V;
    for (int i = 1; i <= N; ++i) cin >> v[i] >> w[i];
    for (int j = 1; j <= V; ++j) {
        for (int i = 1; i <= N; ++i) {
            //内循环表示每个背包可以使用多次
            if (j >= v[i]) f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[V];
    return 0;
    
}