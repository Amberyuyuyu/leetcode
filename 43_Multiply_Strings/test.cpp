class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        string res(len1 + len2, '0');
        for (int i = len2 - 1; i >= 0; i--) {
            for (int j = len1 - 1; j >= 0; j--) {
                int temp = (res[i + j + 1] - '0') + (num1[j] - '0') * (num2[i] - '0');
                res[i + j + 1] = temp % 10 + '0';
                res[i + j] += temp / 10;
            }
        }
        for (int i = 0; i < len1 + len2; i++) {
            if (res[i] != '0') {
                return res.substr(i);
            }
        }
        return "0";
    }
};