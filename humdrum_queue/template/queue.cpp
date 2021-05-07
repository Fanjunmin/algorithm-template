const int N = 1e6;
int q[N], head, tail;

void ff_init()
{
    head = 0;
    tail = -1;
}

bool ff_empty()
{
    return head > tail;
}

void ff_pop_head()
{
    ++head;
}

void ff_pop_tail()
{
    --tail;
}

void ff_push(int x)
{
    q[++tail] = x;
}

void ff_humdrum_quque_process(int a[], int k, int n)
{
    // k is size of windows, n is size of a[]
    ff_init();
    for (int i = 0; i < n; ++i) {
        if (!ff_empty() && head < i - k + 1) ff_pop_head();
        while (!ff_empty() && a[q[tail]] > a[i]) ff_pop_tail;
        ff_push(i);
        // get your need
    }
}