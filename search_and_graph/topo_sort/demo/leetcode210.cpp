class Solution {
private:
    static const int N = 1e5 + 10;
    static const int M = 5010;
    int h[N], d[N];
    int e[M], ne[M], idx;
    int n;
    int q[N], head, tail;

    void init() {
        memset(h, -1, sizeof(h));
        memset(d, 0, sizeof(d));
        idx = 0;
        head = 0;
        tail = -1;
    }

    void add(int a, int b) {
        idx++;
        e[idx] = b; ne[idx] = h[a]; h[a] = idx;
    }

    vector<int> topo_sort() {
        vector<int> topo;
        for (int i = 0; i < n; ++i) {
            if (d[i] == 0) q[++tail] = i;
        }
        while (head <= tail) {
            auto t = q[head++];
            topo.push_back(t);
            for (int i = h[t]; i != -1; i = ne[i]) {
                int j = e[i];
                if (d[j] > 0) --d[j];
                if (d[j] == 0) q[++tail] = j;
            }
        }
        if (n > topo.size()) return {};
        reverse(topo.begin(), topo.end());
        return topo;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        init();
        for (auto pre : prerequisites) {
            add(pre[0], pre[1]);
            d[pre[1]]++;
        }
        return topo_sort();
    }
};