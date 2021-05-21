#define ff_sort(x, y) do {  \
    x ^= y, y ^= x, x ^= y; \
} while(0)


const int N = 1e5;
int h[N];
int len;

/*
    数组模拟小根堆 h[0~len-1]
    节点i的左孩子2*i+1, 右孩子2*i+2
    节点i的父节点(i-1)/2
    整个堆是一个完全二叉树, 第一个非叶子节点len/2-1
    最后一个叶子节点的坐标为len-1, 其父节点是((len-1)-1)/2=len/2-1
*/
void init(int _len)
{
    len = _len;
}

void down(int idx)
{
    int y = idx, l = 2 * idx + 1, r  = 2 * idx + 2;
    if (l < len && h[l] < h[y]) y = l;
    if (r < len && h[r] < h[y]) y = r;
    if (y != idx) {
        ff_sort(h[y], h[idx]);
        down(y);
    }
}

void up(int idx)
{
    int t = idx / 2 - 1;
    if (t > 0 && h[t] > h[idx]) {
        ff_sort(h[t], h[idx]);
        up(t);
    }
}

void head_sort()
{
    int mid = len / 2 - 1;
    for (int i = len / 2 - 1; i >= 0; ++i) {
        down(i);
    }
}