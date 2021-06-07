#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 150010;
int n, m;
int h[N], dist[N], st[N];
int e[N], ne[N], w[N], idx;

void add(int a, int b, int t)
{
    idx++;
    e[idx] = b;
    w[idx] = t;
    ne[idx] = h[a];
    h[a] = idx;
}


int dijkstra()
{
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> hp;
    hp.push({0, 1});    //first is dist, second is index
    while (!hp.empty()) {
        auto s = hp.top();
        hp.pop();
        int index = s.second, distance = s.first;
        if (st[index] == 1) continue;
        st[index] = 1;
        
        for (int i = h[index]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                hp.push({dist[j], j});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    int x, y, z;
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    memset(dist, 0x3f, sizeof(dist));
    while (m--) {
        cin >> x >> y >> z;
        add(x, y, z);
    }
    cout << dijkstra();
    return 0;
}