#define MAX_SIZE (10000)
struct seg_tree {
    int l, r;
    int val;
} t[MAX_SIZE * 4];

// 以max val为例
void _in_build_tree(int p, int l, int r, int a[]) {
    // p 线段树节点, 节点区间[l, r]
    t[p].l = l, t[p].r = r;
    if (l == r) {
        t[p].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    _in_build_tree(2*p+1, l, mid, a);
    _in_build_tree(2*p+2, mid + 1, r, a);
    t[p].val = max(t[2*p+1].val, t[2*p+2].val);
}

void build_tree(int a[], int len) {
    _in_build_tree(0, 0, len - 1, a);
}

void _in_update(int p, int x, int v) {
    if (t[p].l == t[p].r) {
        t[p].val = v;
        return;
    }
    int mid = (t[p].l + t[p].r) >> 1;
    if (x <= mid) _in_update(2*p+1, x, v);
    else _in_update(2*p+2, x, v);
    t[p].val = max(t[2*p+1].val, t[2*p+2].val);
}

void update(int x, int v) {
    _in_update(0, x, v);
}

int _in_query(int p, int l, int r) {
    if (l <= t[p].l && t[p].r <= r) return t[p].val;
    int mid = (t[p].l + t[p].r) >> 1;
    int val = -(1<<30);
    if (l <= mid) val = max(val, _in_query(2*p+1, l, r));
    if (r > mid) val = max(val, _in_query(2*p+2, l, r));
    return val;
}

int query(int p, int l, int r) {
    return _in_query(0, l, r);
}