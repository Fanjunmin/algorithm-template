class Solution {
private:
    void dfs(int u, set<vector<int>> &ret, const vector<int>& nums, vector<int> inc) {
        if (inc.size() > 1) {
            ret.insert(inc);
        }
        for (int i = u; i < nums.size(); ++i) {
            if (inc.empty() || nums[i] >= inc.back()) {
                inc.push_back(nums[i]);
                dfs(i + 1, ret, nums, inc);
                inc.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ret;
        vector<int> inc;
        dfs(0, ret, nums, inc);
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};