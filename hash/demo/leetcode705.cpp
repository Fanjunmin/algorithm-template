#include <cstring>
const int MAXN = 1e6, null = 0x3f3f3f3f;
class MyHashSet {
private:
    int h[MAXN];

    int query(int x) {
        int k = x % MAXN;
        while (h[k] != null && h[k] != x) {
            k++;
            if (k == MAXN) k = 0;
        }
        return k;
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        memset(h, 0x3f, sizeof(h));
    }

    void add(int key) {
        int k = query(key);
        h[k] = key;
    }
    
    void remove(int key) {
        int k = query(key);
        h[k] = null;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int k = query(key);
        return h[k] != null;
    }
};