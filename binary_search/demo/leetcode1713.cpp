class Solution {
private:
    void _binary_search(vector<int> &cp, int num, int sz) {
        int l = 0, r = sz;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (cp[mid] >= num) r = mid;
            else l = mid + 1;
        }
        cp[l] = num;
    }
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> idx_cnt;
        int st = -1, j = 0, ret = 1;
        for (int i = 0; i < target.size(); ++i) idx_cnt[target[i]] = i;
        for (auto& a : arr) {
            if (idx_cnt.find(a) != idx_cnt.end()) {
                a = idx_cnt[a];
                if (st == -1) st = j;
            } else {
                a = -1;
            }
            ++j;
        }
        vector<int> cp(arr.size());
        if (st == -1) return target.size();
        cp[0] = arr[st];
        for (j = st + 1; j < arr.size(); ++j) {
            if (arr[j] != -1) {
                if (arr[j] > cp[ret - 1]) {
                    cp[ret++] = arr[j];
                } else if (arr[j] < cp[ret - 1]) {
                    _binary_search(cp, arr[j], ret - 1);
                }
            }
        }
        return target.size() - ret;
    }
};