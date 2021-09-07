// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (1) {
            int x = (rand7() - 1) * 7  + rand7();   //rand 7 * 7 = 49
            if (x <= 40) return x % 10 + 1;

            x = (x - 40 - 1) * 7 + rand7();     //rand 9 * 7 = 63
            if (x <= 60) return x % 10 + 1;

            x = (x - 60 - 1) * 7 + rand7();     //rand 3 * 7 = 21
            if (x <= 20) return x % 10 + 1;
        }
    }
};