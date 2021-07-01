const int N = 500 + 10;
const int M = 1e6;
class Solution {
private:
    int h[N], st[N];
    int e[M], ne[M], w[M], idx;

    void init() {
        idx = 0;
        memset(e, 0, sizeof(e));
        memset(ne, 0, sizeof(ne));
        memset(h, -1, sizeof(h));
        memset(st, -1, sizeof(st));
    }

    void add(int a, int b) {
        idx++;
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx;
    }

    int bfs(unordered_map<int, vector<int>> &bus_st, int source, int target) {
        auto vec_beg = bus_st[source];
        auto vec_end = bus_st[target];
        queue<int> q;
        for (auto v : vec_beg) {
            //起始站台所在的的公交线路入队列
            q.push(v);
            st[v] = 0;
        }
        while (!q.empty()) {
            auto t = q.front(); // 公交线路
            q.pop();
            int cnt = st[t];
            if (find(vec_end.begin(), vec_end.end(), t) != vec_end.end()) {
                // 在target站台所在的公交线路集合进行查找
                return cnt + 1;
            }

            for (int i = h[t]; i != -1; i = ne[i]) {
                int j = e[i];
                if (st[j] == -1) {
                    st[j] = 1 + cnt;
                    q.push(j);
                }
            }
        }
        return -1;
    }
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (routes.empty()) return -1;
        if (source == target) return 0;
        init();
        unordered_map<int, vector<int>> bus_st;     //记录每个车站所在的公交路线
        int ele;
        for (int i = 0; i < routes.size(); ++i) {
            for (int j = 0; j < routes[i].size(); ++j) {
                ele = routes[i][j];
                if (bus_st.find(ele) == bus_st.end()) {
                    bus_st[ele] = {i};
                } else {
                    bus_st[ele].push_back(i);
                }
            }
        }
        //将每一条公交路线作为图的节点
        for (auto iter = bus_st.begin(); iter != bus_st.end(); ++iter) {
            auto vec = iter->second;
            for (int i = 0; i < vec.size(); ++i) {
                for (int j = i + 1; j < vec.size(); ++j) {
                    add(vec[i], vec[j]);
                    add(vec[j], vec[i]);
                }
            } 
        }
        return bfs(bus_st, source, target);
    }
};