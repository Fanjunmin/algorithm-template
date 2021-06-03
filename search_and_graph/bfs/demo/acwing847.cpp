#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
const int M = 2 * N;
int n, m;
int dist[N], h[N];
int e[M], ne[M], idx;

void init()
{
    memset(h, -1, sizeof(h));
    memset(dist, -1, sizeof(dist));
}

void insert(int a, int b)
{
    idx++;
    e[idx] = b; ne[idx] = h[a]; h[a] = idx;
}

int dfs()
{
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] == -1) {
                dist[j] = 1 + dist[t];
                q.push(j);
            }
        }
    }
    return dist[n];
}

int main()
{
    int a, b;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        insert(a, b);
    }
    cout << dfs();
    return 0;
}