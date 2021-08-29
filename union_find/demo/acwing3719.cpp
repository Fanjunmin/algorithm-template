#include <iostream>
using namespace std;

const int MAX_N = 1010;
int id[MAX_N], sz[MAX_N], cnt;
int N, M;
int a, b;

void _init(int n)
{
    for (int i = 0; i < MAX_N; ++i) {
        id[i] = i;
        sz[i] = 1;
    }
    cnt = n;
}

int _find(int x)
{
    return x == id[x] ? x : id[x] = _find(id[x]);    
}

bool _connected(int x, int y)
{
    return _find(x) == _find(y);
}

bool _union(int x, int y)
{
    int id_x = _find(x), id_y = _find(y);
    if (id_x == id_y) return true;
    if (sz[id_x] < sz[id_y]) {
        sz[id_y] += sz[id_x];
        id[id_x] = id_y;
    } else {
        sz[id_x] += sz[id_y];
        id[id_y] = id_x;
    }
    --cnt;
    return false;
}


int main()
{
    cin >> N >> M;
    _init(N);
    while (M--) {
        cin >> a >> b;
        _union(a, b);
    }
    cout << cnt - 1;
    return 0;
}