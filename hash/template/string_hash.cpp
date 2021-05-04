/*
    prefix string hash
    use unsigned long long replacing mod 2^64
*/
const int N = 1e5 + 10, p = 131;
typedef unsigned long long ULL;
ULL h[N], P[N];
char str[N];

void ff_prefix_init(int n)
{
    h[0] = str[0];
    P[0] = 1;   //p^0;
    for (int i = 1; i < n; ++i) {
        P[i] = P[i - 1] * p;
        h[i] = h[i - 1] * p + str[i];
    }
}

ULL ff_get_hash(int l, int r)
{
    if (l == 0) return h[r];
    return h[r] - h[l - 1] * P[r - l + 1];
}
