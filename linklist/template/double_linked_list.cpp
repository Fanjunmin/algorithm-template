#include <iostream>
using std::cin;
using std::cout;

const int N = 1e5 + 10;
int prev[N], next[N], node[N], idx;

void init()
{
    // head to self
    prev[0] = next[0] = 0;
    idx = 0;
}

void insert(int k, int v)
{
    idx++;
    node[idx] = v;
    next[idx] = next[k];
    prev[next[k]] = idx;
    next[k] = idx;
    prev[idx] = k;
}

void remove(int k)
{
    next[prev[k]] = next[k];
    prev[next[k]] = prev[k];
}
