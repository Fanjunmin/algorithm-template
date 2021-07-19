class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        if (nums.size() <= 1) return nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = 1, max_freq = 1;
        long long sum = 0;
        while (r < nums.size()) {
            sum += (long long) (nums[r] - nums[r - 1]) * (r - l);
            while (sum > k) {
                sum -= nums[r] - nums[l];
                ++l;
            }
            max_freq = max(max_freq, r - l + 1);
            ++r;
        }
        return max_freq;
    }
};