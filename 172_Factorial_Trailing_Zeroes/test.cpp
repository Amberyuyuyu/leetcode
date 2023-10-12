class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        for (int x = n / 5; x > 0; x /= 5) {
            cnt += x;
        }
        return cnt;
    }
};