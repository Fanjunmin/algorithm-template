#include <vector>
using namespace std;

class Solution {
private:
    bool check_left(int mid_num, int condition) {
        return mid_num <= condition;
    }
    bool check_right(int mid_num, int condition) {
        return mid_num >= condition;
    }
private:
    int binary_search(vector<int>&numbers, int l, int r, int value) {
        while (l < r) {
            /*
            int mid = l + r + 1 >> 1;
            if (check_left(numbers[mid], value)) l = mid;
            else r = mid - 1;
            */
            int mid = l + r >> 1;
            if (check_right(numbers[mid], value)) r = mid;
            else l = mid + 1;
        }
        if (numbers[l] == value) return l;
        else return -1;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() <= 1) return {-1, -1};
        int ret = 0;
        for (int i = 0; i < numbers.size() - 1; ++i) {
            ret = binary_search(numbers, i + 1, numbers.size() - 1,
                target - numbers[i]);
            if (ret != -1) {
                return {i + 1, ret + 1};
            }
        }
        return {-1, -1};
    }
};