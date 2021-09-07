class Solution {
private:
    double _r, _x, _y;
public:
    Solution(double radius, double x_center, double y_center) {
        _r = radius, _x = x_center, _y = y_center;
    }
    
    vector<double> randPoint() {
        while (1) {
            double x = rand() / double(RAND_MAX) * 2 - 1;
            double y = rand() / double(RAND_MAX) * 2 - 1;
            // 拒绝采样
            if (x * x + y * y <= 1) return {x * _r + _x, y * _r + _y};
        }
        return {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */