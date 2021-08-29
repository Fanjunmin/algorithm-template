#define ff_sort(x, y) do {  \
    (x) ^= (y), (y) ^= (x), (x) ^= (y); \
} while(0)

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j) ff_sort(q[i], q[j]);
    } 
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}