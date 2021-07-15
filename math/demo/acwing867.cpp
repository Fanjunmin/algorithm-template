#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5;
int prime[N], cnt[N];
int idx;

void init()
{
    memset(prime, 0, sizeof(prime));
    memset(cnt, 0, sizeof(cnt));
    idx = 0;
}

void get_prime(int a)
{
    for (int i = 2; i <= a / i; ++i) {
        if (a % i == 0) {
            prime[idx] = i, cnt[idx] = 0;
            while (a % i == 0) {
                a /= i;
                cnt[idx]++;
            }
            ++idx;
        }
    }
    if (a > 1) {
        prime[idx] = a, cnt[idx++] = 1;
    }
    for (int i = 0; i < idx; ++i) {
        cout << prime[i] << " " << cnt[i] << endl;
    }
    cout << endl;
}

int main()
{
    int a, n;
    cin >> n;
    while (n--) {
        cin >> a;
        init();
        get_prime(a);
    }
    return 0;
}