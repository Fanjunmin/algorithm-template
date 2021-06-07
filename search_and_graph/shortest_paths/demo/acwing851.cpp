#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int M = 2 * N;
int n, m;
int h[N], dist[M], st[N];
int e[M], ne[M], wt[M], idx;

void init()
{
    memset(h, -1, sizeof(h));
    memset(dist, 0x3f, sizeof(dist));
}

void add(int a, int b, int t)
{
    idx++;
    wt[idx] = t;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

int spfa()
{
    queue<int> q;
    dist[1] = 0;
    st[1] = 1;
    q.push(1);
    
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        st[t] = 0;
        
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > wt[i] + dist[t]) {
                dist[j] = wt[i] + dist[t];
                if (st[j] == 0) {
                    q.push(j);
                    st[j] = 1;
                }
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}


int main()
{
    cin >> n >> m;
    int x, y, z;
    init();
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> z;
        add(x, y, z);
    }
    int ret = spfa();
    if (ret == -1) cout << "impossible" << endl;
    else cout << spfa() << endl;
    return 0;
}