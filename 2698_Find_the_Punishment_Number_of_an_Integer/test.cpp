class Solution {
public:
    bool check(int num, string& s, int stringIndex, int sum) {
        if (stringIndex == s.length()) {
            return sum == num;
        }
        int currentNum = 0;
        for (int i = stringIndex; i < s.length(); i++) {
            currentNum = currentNum * 10 + (s[i] - '0');
            if (currentNum + sum > num) {
                return false;
            }
            if (check(num, s, i + 1, currentNum + sum)) {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            string squareStr = to_string(square);
            if (check(i, squareStr, 0, 0)) {
                result += square;
            }
        }
        return result;
    }
};