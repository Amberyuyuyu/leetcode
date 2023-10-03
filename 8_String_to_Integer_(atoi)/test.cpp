class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long tmp = 0;
        while (s[i] == ' ') {
            ++i;
        }
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i++] == '-') ? -1 : 1;
        }
        while (s[i] >= '0' && s[i] <= '9') {
            tmp *= 10;
            tmp += s[i] - '0';
            if (tmp > (long long)INT_MAX || tmp < (long long)INT_MIN) {
                return sign > 0 ? INT_MAX : INT_MIN;
            }
            ++i;
        }
        return sign * tmp;
    }
};