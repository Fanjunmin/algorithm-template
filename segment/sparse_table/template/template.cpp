#include <math.h>
const int N = 1000;
const int k = log2(N);
int F[N][k];
int a[N];

void st_init()
{
    for (int i = 0; i < N; ++i) F[i][0] = a[i];
    for (int j = 1; j < k; ++j) {
        for (int i = 0; i + (1 << j) - 1 < N; ++i) {
            F[i][j] = max(F[i][j - 1] + F[i + 1 << (j - 1)][j - 1]);
        }
    }
}

int st_query(int l, int r)
{
    //[l, r] -> [l, 2^i-1] [r+1-2^i, r]
    int i = log2(r - l + 1);
    return max(F[l][i], F[r + 1 - (1 << (i))][i]);
}