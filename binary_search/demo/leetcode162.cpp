#include <vector>
using namespace std;

class Solution {
private:
    bool check(vector<int>& nums, int mid) {
        return nums[mid] > nums[mid + 1];
    }
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(nums, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};