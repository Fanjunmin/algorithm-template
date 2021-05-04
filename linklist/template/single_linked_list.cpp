const int N = 1e5 + 10;
int node[N], next[N], idx;

void init()
{
    // head is the first element of index = 0
    next[0] = -1;
    idx = 0;
}

void insert(int k, int v)
{
    idx++;
    node[idx] = v;
    next[idx] = next[k];
    next[k] = idx;
}

void remove(int k)
{
    next[k] = next[next[k]];
}

