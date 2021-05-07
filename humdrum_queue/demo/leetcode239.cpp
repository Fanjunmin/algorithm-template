#include <vector>
using namespace std;

const int N = 1e5 + 10;
class Solution {
private:
    int head, tail;
    int q[N];

    void init() {
        head = 0, tail = -1;
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res(nums.size() - k + 1);
        int j = 0;
        init();
        for (int i = 0; i < nums.size(); ++i) {
            if (head <= tail && q[head] < i - k + 1) head++;
            while (head <= tail && nums[q[tail]] < nums[i]) tail--;
            q[++tail] = i;
            if (i >= k - 1) res[j++] = nums[q[head]]; 
        }
        return res;
    }
};