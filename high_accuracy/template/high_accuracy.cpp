#include <vector>
#include <algorithm>
/*
    123456789
    A = {9,8,7,6,5,4,3,2,1}
*/

/* 
    high accuracy add
*/
std::vector<int> add(const std::vector<int> &A, const std::vector<int> &B)
{
    std::vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); ++i) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back((t + 10) % 10);
        t /= 10;
    }
    if (t == 1) C.push_back(1);
    return C;
}

/*
    high accuracy sub
*/
static bool comp(const std::vector<int> &A, const std::vector<int> &B)
{
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; --i) {
        if (A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}

std::vector<int> sub(const std::vector<int> &A, const std::vector<int> &B)
{
    // assume A >= B;
    std::vector<int> C;
    for (int i = 0, t = 0; i < A.size(); ++i) {
        t += A[i];
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = -1;
        else t = 0;
    }
    while (C.size() > 1 && C[C.size() - 1] == 0) C.pop_back();
    return C;
}

/* 
    high accuracy mul
*/
std::vector<int> mul(const std::vector<int> &A, const int &b)
{
    std::vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; ++i) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C[C.size() - 1] == 0) C.pop_back();
    return C;
}

/* 
    high accuracy div
*/
std::vector<int> div(const std::vector<int> &A, const int &b, int &r)
{
    std::vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; --i) {
        // high bit to low bit
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C[C.size() - 1] == 0) C.pop_back();
    return C;
}