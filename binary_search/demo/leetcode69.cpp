typedef long long LL;
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            LL mid = (LL)l + r + 1 >> 1;
            LL check = (LL) mid * mid;
            if (check <= x) l = mid;
            else r = mid - 1;
        }
        return l;
    }
    /*
    int mySqrt(int x) {
        if (x <= 1) return x;
        int l = 0, r = x;
        while (l < r) {
            LL mid = (LL)l + r >> 1;
            LL check = (LL) mid * mid;
            if (check > x) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    */
};