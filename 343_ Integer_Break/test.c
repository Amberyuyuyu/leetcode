int integerBreak(int n) {
    int dp[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
    }
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i - 1; j++) {
            int tmp = fmax(j * (i - j), dp[i - j] * j);
            dp[i] = fmax(tmp, dp[i]);
        }
    }
    return dp[n];
}