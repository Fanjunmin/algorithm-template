#include <iostream>
using namespace std;
const int N = 1e5;
int divisor[N];
int cnt;

void get_divisor(int a)
{
    cnt = 0;
    for (int i = 1; i <= a / i; ++i) {
        if (a % i == 0) {
            divisor[cnt++] = i;
            cout << i << " ";
            if (a / i == i) continue;
        }
    }
    for (int i = cnt - 1; i >= 0; --i) {
        if (a / divisor[i] != divisor[i]) cout << (a / divisor[i]) << " "; 
    }
    cout << endl;
}

int main()
{
    int n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        get_divisor(a);
    }
    return 0;
}