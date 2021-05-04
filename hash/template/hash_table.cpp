/*
    data in [-10^9, 10^9]
    hash to N = 10003
*/

/*
    method one: open chain method
*/
#include <cstring>
const int N = 10003;
int h1[N], node[N], next[N], idx;

void ff_hash_init1()
{
    memset(h1, -1, sizeof(h1));
    next[0] = -1;
    idx = 0;
}

void ff_list_insert1(int k, int v)
{
    ++idx;
    node[idx] = v;
    next[idx] = h1[k];
    h1[k] = idx;
}

void ff_hash_insert1(int x)
{
    int k = (x % N + N) % N;
    ff_list_insert1(k, x);
}

bool ff_quary1(int x)
{
    int k = (x % N + N) % N;
    for (int i = h1[k]; i != -1; i = next[i]) {
        if (node[i] == x) return true;
    }
    return false;
}


/*
    method two: open addressing method
*/
const int M = 20003, null = 0x3f3f3f3f;
int h2[M];

void ff_init2()
{
    memset(h2, 0x3f, sizeof(h2));
}

int query(int x)
{
    int k = (x % M + M) % M;
    while (h2[k] != null && h2[k] != x) {
        k++;
        if (k == N) k = 0;
    }
    return k;
}

void insert(int x)
{
    int k = query(x);
    h2[k] = x;
}
