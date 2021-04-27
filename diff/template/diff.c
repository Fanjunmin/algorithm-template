void init1(int *q, int n)
{
    for (int i = 0; i < n; ++i) {
        insert(q, i, i, q[i]);
    }
}

void init2(int **q, int n, int m)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            insert(q, i, j, i, j, q[i][j]);
        }
    }
}

int insert1(int *q, int l, int r, int c)
{
    q[l] += c;
    q[r + 1] -= c;
}

int insert2(int **q, int x1, int y1, int x2, int y2, int c)
{
    q[x1][y1] += c;
    q[x2 + 1][y1] -= c;
    q[x1][y2 + 1] -= c;
    q[x2 + 1][y2 + 1] += c;
}
