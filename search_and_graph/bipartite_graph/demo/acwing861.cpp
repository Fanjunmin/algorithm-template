#include <cstring>
#include <iostream>

using namespace std;
const int N = 510, M = 1e5 + 10;
int h[N], e[M], ne[M], idx;
int st[N], match[N];
int n1, n2, m, u, v;

void add(int a, int b)
{
    idx++;
    e[idx] = b, ne[idx] = h[a], h[a] = idx;
}

bool find(int x)
{
    st[x] = 1;
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if(st[j] == 0) {
            st[j] = 1;
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        add(u, v);
    }
    
    int res = 0;
    for (int i =1; i <= n1; ++i) {
        memset(st, 0, sizeof(st));
        if (find(i)) res++; 
    }
    cout << res;
    return 0;
}