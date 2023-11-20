class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        for (int x = num; x; x /= 10) {
            ans += num % (x % 10) == 0;
        }
        return ans;
    }
};