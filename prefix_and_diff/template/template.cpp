const int N = 1e3;
const int M = 1e3;
int a1[N], S1[N + 1], D1[N + 1];
int a2[M][N], S2[M + 1][N + 1], D2[M + 1][N + 1];

int get_s1() {
    for (int i = 0; i < N; ++i) {
        S1[i + 1] = S1[i] + a1[i];
    }
}

int get_s2() {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            S2[i + 1][j + 1] += S2[i + 1][j] + S2[i][j + 1] - a2[i][j];
        }
    }
}

void insert_d1(int l, int r, int c) {
    D1[r + 1] -= c;
    D1[l] += c;
}

void get_d1() {
    for (int i = 0; i < N; ++i) {
        insert_d1(i, i, a1[i]);
    }
}

void insert_d2(int x1, int y1, int x2, int y2, int c) {
    D2[x1][y1] += c;
    D2[x1][y2 + 1] -= c;
    D2[x2 + 1][y1] -= c;
    D2[x2 + 1][y2 + 1] += c;
}

void get_d1() {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            insert_d2(i, j, i, j, a2[i][j]);
        }
    }
}