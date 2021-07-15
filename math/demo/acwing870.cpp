#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int M = 1e9 + 7;
const int N = 1e5;
int divisor[N];
unordered_map<int, int> cnt;


void get_divisor_num(int a)
{
    int j = 0;
    for (int i = 2; i <= a / i; ++i) {
        if (a % i == 0) {
            divisor[j] = i;
            while (a % i == 0) {
                a /= i;
                cnt[i]++;
            }
        }
        ++j;
    }
    if (a > 1) {
        divisor[j] = a, cnt[a]++;
    }
    return;
}

int main()
{
    int n, a;
    LL num = 1;
    cin >> n;
    while (n--) {
        cin >> a;
        get_divisor_num(a);
    }
    for (auto c : cnt) num = num * (c.second + 1) % M;
    cout << num;
    return 0;
}