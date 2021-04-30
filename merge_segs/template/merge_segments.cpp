#include <vector>
#include <algorithm>
typedef std::pair<int, int> PII;
#define ff_max(a, b) ((a) < (b) ? (a) : (b)) 

int merge(const std::vector<PII> &segs)
{
    std::vector<PII> res;
    int l = INT32_MIN, r = INT32_MIN;
    std::sort(segs.begin(), segs.end());
    for (auto seg : segs) {
        if (r < seg.first) {
            res.push_back({l, r});
            l = seg.first, r = seg.second;
        } else {
            r = ff_max(r, seg.second);
        }
    }
    return res.size();
}
