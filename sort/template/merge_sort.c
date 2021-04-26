const int N = 1e6;
static int tmp[N];

void merge_sort(int m[], int l, int r)
{
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(m, l, mid);
    merge_sort(m, mid + 1, r);

    //merge
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) tmp[k++] = m[i] <= m[j] ? m[i++] : m[j++];
    while (i <= mid) tmp[k++] = m[i++];
    while (j <= r) tmp[k++] = m[j++];
    for (i = l, k = 0; i <= r; i++, k++) m[i] = tmp[k];
}

long long merge_sort_get_reverse(int m[], int l, int r)
{
    if (l >= r) return 0;
    int mid = l + r >> 1;
    long long ret = merge_sort_get_reverse(m, l, mid) +
        merge_sort_get_reverse(m, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (m[i] <= m[j]) {
            tmp[k++] = m[i++];
        } else {
            tmp[k++] = m[j++];
            ret += mid - i + 1;
        }
    }
    while (i <= mid) tmp[k++] = m[i++];
    while (j <= r) tmp[k++] = m[j++];
    for (i = l, k = 0; i <= r; ++i, ++k) m[i] = tmp[k];
    return ret;
}