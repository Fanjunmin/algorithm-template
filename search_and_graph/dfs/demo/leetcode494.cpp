class Solution {
private:
    int dfs(int u, vector<int>& nums, int target) {
        if (u == nums.size()) {
            return target == 0 ? 1 : 0;
        }
        int cnt = 0;
        cnt += dfs(u + 1, nums, target + nums[u]);
        cnt += dfs(u + 1, nums, target - nums[u]);
        return cnt;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, nums, target);
    }
};