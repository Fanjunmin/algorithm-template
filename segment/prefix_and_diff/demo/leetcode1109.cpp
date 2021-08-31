class Solution {
private:
    void insert_diff(vector<int> &diff, int l, int r, int c) {
        diff[l] += c;
        diff[r + 1] -= c;
    }
    void restruct(vector<int> &ans, vector<int> &diff) {
        ans[0] = diff[0];
        for (int i = 1; i < ans.size(); ++i) {
            ans[i] = ans[i - 1] + diff[i];
        }
    }
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0), diff(n + 1, 0);
        for (auto b : bookings) {
            insert_diff(diff, b[0] - 1, b[1] - 1, b[2]);
        }
        restruct(ans, diff);
        return ans;
    }
};