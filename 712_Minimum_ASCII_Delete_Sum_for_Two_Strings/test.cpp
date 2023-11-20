class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int count = 0;
        for (int i = 0; i < s1.length(); ++i) {
            count += s1[i];
        }
        for (int i = 0; i < s2.length(); ++i) {
            count += s2[i];
        }
        if (s1.length() == 0 || s2.length() == 0) {
            return count;
        }
        int dp[s1.leng th()][s2.length()];
        if (s1[0] == s2[0]) {
            dp[0][0] = s1[0];
        }
        else {
            dp[0][0] = 0;
        }
        for (int i = 1; i < s1.length(); ++i) {
            if (s1[i] == s2[0]) {
                dp[i][0] = s1[i];
            }
            else {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int i = 1; i < s2.length(); ++i) {
            if (s2[i] == s1[0]) {
                dp[0][i] = s2[i];
            }
            else {
                dp[0][i] = dp[0][i - 1];
            }
        }
        for (int i = 1; i < s1.length(); ++i) {
            for (int j = 1; j < s2.length(); ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (s1[i] == s2[j]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + s1[i]);
                }
            }
        }
        return count - 2 * dp[s1.length() - 1][s2.length() - 1];
    }
};