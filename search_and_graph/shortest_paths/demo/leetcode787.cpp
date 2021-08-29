class Solution {
private:
    const int init_price = 0x3f3f3f3f;
    int prices[101];
    int back_up[101];
    void init() {
        memset(prices, 0x3f, sizeof(prices));
        memset(back_up, 0x3f, sizeof(back_up));
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //bellman ford algo
        init();
        prices[src] = 0;
        int from, to, price;
        for (int i = 0; i <= k; ++i) {
            memmove(back_up, prices, sizeof(prices));
            for (int j = 0; j < flights.size(); ++j) {
                from = flights[j][0], to = flights[j][1], price = flights[j][2];
                prices[to] = min(prices[to], back_up[from] + price);
            }
        }
        if (prices[dst] > init_price / 2) return -1;
        return prices[dst];
    }
};