class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0) {
            return true;
        }
        for (int a = 1; a < (int)sqrt(c) + 1; ++a) {
            double b = sqrt(c - a * a);
            if (b == (int)b) {
                return true;
            }
        }
        return false;
    }
};