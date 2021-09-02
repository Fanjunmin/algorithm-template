
class Solution {
private:
    const static int N = 100010;
    const static int K = 18;   //log2(N)
    int F[N][K] = {0};
    void st_init(vector<int>& arr) {
        int n = arr.size();
        int k = log2(n);
        for (int i = 0; i < n; ++i) F[i][0] = arr[i];
        for (int j = 1; j <= k; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                F[i][j] = F[i][j - 1] & F[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    int st_query(int l, int r) {
        int k = log2(r - l + 1);
        return F[l][k] & F[r + 1 - (1 << k)][k];
    }
public:
    int closestToTarget(vector<int>& arr, int target) {
        if (arr.empty() || target == 0) return 0;
        st_init(arr);
        int min_offset = INT_MAX;
        int v = 0;
        for (int i = 0; i < arr.size(); ++i) {
            /*  
                Monotonicity: st_query(i, k) >= st_query(i, k)
            */
            int l = i, r = arr.size() - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (st_query(i, mid) >= target) l = mid;
                else r = mid - 1;
            }
            min_offset = min(min_offset, abs(st_query(i, l) - target));
            if (l + 1 < arr.size() && st_query(i, l + 1))
                min_offset = min(min_offset, abs(st_query(i, l + 1) - target));
        }
        return min_offset;
    }
};