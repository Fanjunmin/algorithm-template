#include <string>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e5, p = 131;
ULL h[N], P[N];
class Solution {
private:
    void init(const string &s) {
        P[0] = 1, h[0] = s[0];
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
    string longestPrefix(string s) {
        if (s.size() <= 1) return "";
        init(s);
        for (int i = s.size() - 2; i >= 0; --i) {
            if (get(0, i) == get(s.size() - 1 - i, s.size() - 1)) {
                return s.substr(0, i + 1);
            }
        }
        return "";
    }
};