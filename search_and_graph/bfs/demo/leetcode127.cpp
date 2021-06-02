class Solution {
private:
    unordered_map<string, int> umsi, umsi_dist;
    string end_word;
    int bfs(const string& st) {
        queue<string> qs;
        int len = st.size();
        qs.push(st);
        umsi_dist[st] = 1;
        while (!qs.empty()) {
            auto t = qs.front();
            qs.pop();
            int dist = umsi_dist[t];
            if (t == end_word) {
                return dist;
            }
            for (int i = 0; i < len; ++i) {
                char c = t[i];
                for (int j = 0; j < 26; ++j) {
                    t[i] = 'a' + j;
                    if (umsi.count(t) != 0 && umsi_dist.count(t) == 0) {
                        umsi_dist[t] = dist + 1;
                        qs.push(t);
                    }
                    t[i] = c;
                }
            }
        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (auto word : wordList) ++umsi[word];
        end_word = endWord;
        return bfs(beginWord);
    }
};