#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int st[N], prime[N];    //st[k]==1代表合数标记
int cnt = 0;

void era_primes(int n)
{
    // O(nloglogn)
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {
            prime[cnt++] = i;
        }
        for (int j = i; j <= n / i; ++j) st[i * j] = 1;
    }
}

void linear_primes(int n)
{
    // O(n)
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && prime[j] <= n / i; ++j) {
            st[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}


int main()
{
    int n;
    cin >> n;
    linear_primes(n);
    cout << cnt;
    return 0;
}