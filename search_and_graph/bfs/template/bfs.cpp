#include <cstring>
const int N = 1e5;
const int M = 2 * N;
int h[N];   // for all node 
int e[M], ne[M], idx;   // for linked list
int q[N], head, tail;   // for queue

void ff_init()
{
    memset(h, -1, sizeof(h));
    head = 0, tail = -1;
}

bool ff_queue_empty()
{
    return head > tail;
}

void ff_insert(int a, int b)
{
    // node a -> node b, there is a directed edge
    idx++;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

void bfs()
{
    ff_init();
    //suppose the first node in queue
    h[++tail] = 1;
    while (!ff_queue_empty()) {
        int t = h[head++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            // to do
        }
    }
}