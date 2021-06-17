#include <unordered_map>
enum {
    CH_NUM = 0,
    CH_SIGN,
    CH_E,
    CH_DOT,
    CH_INVAILD
};
enum {
    ST_INIT = 0,
    ST_SIGN,
    ST_INT,
    ST_DOT1,
    ST_DOT2,
    ST_FLOAT,
    ST_E,
    ST_E_SIGN,
    ST_E_INT,
    ST_INVALID,
};

enum {
    END_STATE = 0,
    MIDDLE_STATE,
};

const int g_state[] = {
    MIDDLE_STATE, MIDDLE_STATE, END_STATE, END_STATE, MIDDLE_STATE, END_STATE, MIDDLE_STATE, MIDDLE_STATE, END_STATE
};
const unordered_map<int, unordered_map<int, int>> st2st = {
    {   ST_INIT,   {{CH_NUM, ST_INT}, {CH_SIGN, ST_SIGN}, {CH_DOT, ST_DOT2}}  },
    {   ST_SIGN,   {{CH_NUM, ST_INT}, {CH_DOT, ST_DOT2}}                     },
    {   ST_INT,    {{CH_NUM, ST_INT}, {CH_E, ST_E}, {CH_DOT, ST_DOT1}}        },
    {   ST_DOT1,   {{CH_NUM, ST_FLOAT}, {CH_E, ST_E}}                         },
    {   ST_DOT2,   {{CH_NUM, ST_FLOAT}}                                       },
    {   ST_FLOAT,  {{CH_NUM, ST_FLOAT}, {CH_E, ST_E}}                         },
    {   ST_E,      {{CH_NUM, ST_E_INT}, {CH_SIGN, ST_E_SIGN}}                 },
    {   ST_E_SIGN, {{CH_NUM, ST_E_INT}}                                       },
    {   ST_E_INT,  {{CH_NUM, ST_E_INT}}                                       }
};
class Solution {
private:
    int get_ch_type(char ch) {
        if (ch >= '0' && ch <= '9') {
            return CH_NUM;
        } else if (ch == '+' || ch == '-') {
            return CH_SIGN;
        } else if (ch == 'e' || ch == 'E') {
            return CH_E;
        } else if (ch == '.') {
            return CH_DOT;
        } else {
            return CH_INVAILD;
        }
    }

public:
    bool isNumber(string s) {
        int st = ST_INIT;
        for (auto ch : s) {
            auto tp = get_ch_type(ch);
            if (tp == CH_INVAILD) {
                return false;
            }
            auto t = st2st.at(st).find(tp);
            if (t == st2st.at(st).end()) {
                return false;
            }
            st = st2st.at(st).at(tp);
        }
        return g_state[st] == END_STATE;
    }
};