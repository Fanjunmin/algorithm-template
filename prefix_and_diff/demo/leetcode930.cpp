class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, cnt = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            hash[sum]++;
            sum += nums[i];
            cnt += hash[sum - goal];
        }
        return cnt;
    }
};