const int N = 1e9 + 7;
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        if (nums1 == nums2) return 0;
        vector<int> temp(nums1);
        sort(temp.begin(), temp.end());
        int sum = 0, rep = 0;
        int max_diff = 0, diff = 0, diff_i = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            diff_i = abs(nums1[i] - nums2[i]);
            sum = (sum + diff_i) % N;
            int l = 0, r = nums1.size() - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (temp[mid] > nums2[i]) r = mid;
                else l = mid + 1;
            }
            if (l == 0) {
                diff = diff_i - min(abs(temp[l] - nums2[i]), abs(temp[l + 1] - nums2[i]));
            } else {
                diff = diff_i - min(abs(temp[l] - nums2[i]), abs(temp[l - 1] - nums2[i]));
            }
            if (diff > max_diff) {
                max_diff = diff;
            }
        }
        return (sum - max_diff + N) % N;
    }
};