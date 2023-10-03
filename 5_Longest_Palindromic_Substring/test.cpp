class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len < 2) {
            return s;
        }
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }
        int maxLen = 0;
        int begin = 0;
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                    }
                    else if (dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                    if (dp[i][j] && j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        begin = i;
                    }
                }
            }
        }
        string ret = s.substr(begin, maxLen);
        return ret;

    }
};