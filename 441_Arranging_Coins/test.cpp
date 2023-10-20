class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 1, r = n;
        while (l < r) {
            long long mid = (l + r + 1) / 2;
            long long need = (1 + mid) * mid / 2;
            if (n >= need) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        return l;
    }
};