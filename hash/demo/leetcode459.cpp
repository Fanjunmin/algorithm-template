#include <string>
using namespace std;
typedef unsigned long long ULL;
const int N = 2e5, p = 131;
ULL h[N], P[N];
class Solution {
private:
    void init(const string &s) {
        h[0] = s[0];
        P[0] = 1;
        for (int i = 1; i < s.size(); ++i) {
            P[i] = P[i - 1] * p;
            h[i] = h[i - 1] * p + s[i];
        }
    }

    ULL get(int l, int r) {
        if (l == 0) return h[r];
        return h[r] - h[l - 1] * P[r - l + 1];
    }
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        init(ss);
        ULL target = get(0, s.size() - 1);
        for (int i = 1; i <= s.size() - 1; ++i) {
            if (target == get(i, s.size() + i - 1)) {
                return true;
            }
        }
        return false;
    }
};