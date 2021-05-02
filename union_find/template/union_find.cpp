#include <stdio.h>

const int N = 1e7;
int id[N], sz[N], cnt;

void ff_init(int n)
{
    for (int i = 0; i < n; ++i) {
        id[i] = i;
        sz[i] = 1;
    }
    cnt = n;
}

int ff_find(int x)
{
    // return id[x] == x ? x : id[x] = ff_find(id[x]);
    int temp = x;
    while (x != id[x]) x = id[x];
    while (x != id[temp]) {
        int q = id[temp];
        id[temp] = x;
        temp = q;
    }
    return x;
}

bool ff_is_connected(int x, int y)
{
    return ff_find(x) == ff_find(y); 
}

bool ff_union(int x, int y)
{
    int root_x = ff_find(x), root_y = ff_find(y);
    if (root_x == root_y) return false;
    if (sz[root_x] > sz[root_y]) {
        sz[root_x] += sz[root_y];
        id[root_y] = root_x;
    } else {
        sz[root_y] += sz[root_x];
        id[root_x] = root_y;
    }
    --cnt;
    return true;
}

int ff_get_cnt()
{
    return cnt;
}

int ff_get_sz(int x)
{
    return id[ff_find(x)];
}

// for debug
void debug(int n)
{
    for (int i = 0; i < n; ++i) {
        printf("id[%d]: %d, sz[%d] : %d; ", i, ff_find(i), i, sz[i]);
    }
    printf("\n");
    printf("cnt: %d\n", cnt);
}

