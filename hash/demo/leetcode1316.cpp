#include <string>
#include <map>
using std::string;
using std::map;
typedef unsigned long long ULL;
const int N = 2001, p = 131;

class Solution {
private:
    ULL h[N], P[N];
    void init(string text) {
        h[0] = text[0];
        P[0] = 1;
        for (int i = 1; i < text.size(); ++i) {
            P[i] = P[i - 1] * p;
            h[i] = h[i - 1] * p + text[i];
        }
    }
    ULL get_hash(int l, int r) {
        if (l == 0) return h[r];
        return h[r] - h[l - 1] * P[r - l + 1];
    }
public:
    int distinctEchoSubstrings(string text) {
        if (text.empty()) return 0;
        init(text);
        map<ULL, int> mui;
        int cnt = 0;
        int hash_l, hash_r;
        for (int i = 1; i < text.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                hash_l = get_hash(j, i + j >> 1);
                hash_r = get_hash(i + j + 1 >> 1, i);
                if ((i - j) % 2 &&  hash_l == hash_r) {
                    if (mui.count(hash_r) == 0) {
                        ++cnt;
                        mui[hash_r] ++;
                    }
                }
            }
        }
        return cnt;
    }
};