#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

const string target = "12345678x"; 
string st = "         ";
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
queue<string> qs;
unordered_map<string, int> msi;

int bfs(string st)
{
    qs.push(st);
    msi[st] = 0;
    while (!qs.empty()) {
        auto t = qs.front();
        qs.pop();
        int cnt = msi[t];
        if (t == target) {
            return cnt;
        }
        int pos = t.find('x');
        for (int i = 0; i < 4; ++i) {
            int x = pos / 3 + dx[i], y = pos % 3 + dy[i];
            if (x >= 0 && x < 3 && y >= 0 && y < 3) {
                swap(t[pos], t[x * 3 + y]);
                if (msi.count(t) == 0) {
                    msi[t] = cnt + 1;
                    qs.push(t);
                }
                swap(t[pos], t[x * 3 + y]);
            }
        }
    }
    return -1;
}

int main()
{
    char c;
    for (int i = 0; i < 9; ++i) {
        cin >> c;
        st[i] = c;
    }
    cout << bfs(st);
    return 0;
}