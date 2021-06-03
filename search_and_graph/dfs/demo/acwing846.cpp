#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
const int M = 2 * N;
int h[N], st[N];
int e[M], ne[M], idx;
int n, max_cnt = N;

void init()
{
    memset(h, -1, sizeof(h));
}

void insert(int a, int b)
{
    idx++; e[idx] = b;
    ne[idx] = h[a]; h[a] = idx;
}

int dfs(int u)
{
    st[u] = 1;
    int cnt = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int k = dfs(j);
            res = max(res, k);  //删除节点i后最大的连通块的点数
            cnt += k;   //节点i以及i指向的所有连通块的总点数
        }
    }
    res = max(res, n - cnt);
    max_cnt = min(res, max_cnt);
    return cnt;
}

int main()
{
    int a, b;
    cin >> n;
    init();
    for (int i = 0; i < n - 1; ++i) {
       cin >> a >> b;
       insert(a, b), insert(b, a);
    }
    dfs(1);
    cout << max_cnt;
    
    return 0;
}