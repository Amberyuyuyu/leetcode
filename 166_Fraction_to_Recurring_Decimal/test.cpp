class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long n = numerator, d = denominator;
        string ret;
        if (n * d < 0) {
            ret += "-";
        }
        long long a = n / d;
        if (a < 0) {
            a *= -1;
        }
        ret += to_string(a);
        if (n < 0) {
            n *= -1;
        }
        if (d < 0) {
            d *= -1;
        }
        n %= d;
        if (n == 0) {
            return ret;
        }
        ret += ".";
        unordered_map<int, int> st;
        string t;
        int index = 0;
        while (n && !st.count(n)) {
            st[n] = index++;
            n *= 10;
            t.push_back((char)(n / d + '0'));
            n %= d;
        }
        if (n != 0) {
            ret += t.substr(0, st[n]) + "(" + t.substr(st[n]) + ")";
        }
        else {
            ret += t;
        }
        return ret;
    }
};