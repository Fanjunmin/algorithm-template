#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int q[N];   //q[k]表示长度为k的上升子序列中的最小的末尾元素的值
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int k = 0;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = k;
        while (l < r) {
            // 二分查找q[N]中的第一个小于a[i]的元素
            int mid = l + r + 1 >> 1;
            if (q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        q[r + 1] = a[i];    //将a[i]更新到q[r+1]
        k = max(k, r + 1);
    }
    cout << k;
    return 0;
}