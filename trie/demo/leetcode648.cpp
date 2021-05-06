/*
time:
1996 ms beats 5.03%
memory:
122.8 MB beats 30.28%
to do: optomize
*/

#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int N = 1000000;
int son[N][26];
int cnt[N];
class Solution {
private:
    int idx;

    void init() {
        idx = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(son, 0, sizeof(son));
    }

    void insert(const string &str) {
        int p = 0;
        for (int i = 0; i < str.size(); ++i) {
            int u = str[i] - 'a';
            if (!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }
    
    int get_root_idx(const string &str) {
        int p = 0, i = 0;
        for (i = 0; i < str.size(); ++i) {
            int u = str[i] - 'a';
            if (cnt[p]) return i;
            if (!son[p][u]) return 0;
            p = son[p][u];
        }
        return p;
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        init();
        for (auto dic : dictionary) insert(dic);
        string ret, sub_sen;
        int root_idx, i = 0, j = 0;
        for (i = 0; i < sentence.size();) {
            if (sentence[i] == ' ') {
                sub_sen = sentence.substr(j, i - j);
                root_idx = get_root_idx(sub_sen);
                if (root_idx) {
                    ret.append(sub_sen.substr(0, root_idx));
                    ret.append(" ");
                } else {
                    ret.append(sub_sen);
                    ret.append(" ");
                }
                j = ++i;
            } else {
                ++i;
            }
        }
        sub_sen = sentence.substr(j, i - j);
        root_idx = get_root_idx(sub_sen);
        if (root_idx) ret.append(sub_sen.substr(0, root_idx));
        else ret.append(sub_sen);
        return ret;
    }
};