const int INF = 1e5;
class Solution {
private:
    void _binary_search(vector<int> &cp, int num, int sz) {
        // find the fist element which >= num
        int l = 0, r = sz;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (cp[mid] >= num) r = mid;
            else l = mid + 1;
        }
        cp[l] = num;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
            O(NlogN) binary search
        */
        if (nums.empty()) return 0;
        vector<int> cp(nums.size(), INF);
        cp[0] = nums[0];
        int ret = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < cp[ret - 1]) {
                _binary_search(cp, nums[i], ret);
            } else if (nums[i] > cp[ret - 1]) {
                cp[ret++] = nums[i];
            }
        }
        return ret;
    }
};