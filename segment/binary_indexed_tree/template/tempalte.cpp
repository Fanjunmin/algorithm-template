const int N = 10000;
int a[N], c[N];

int lowbit(int x) {
    return x&-x;
}

void update(int x, int y) {
    for (; x <= N; x += lowbit(x)) c[x] += y;
}

int ask(int x) {
    int ret = 0;
    for (; x; x -= lowbit(x)) ret += c[x];
    return ret;
}

int query(int l, int r) {
    // l > 0
    return ask(r) - ask(l - 1);
}

void init() {
    for (int x = 1; x < N; ++x) update(x, a[x]);
}