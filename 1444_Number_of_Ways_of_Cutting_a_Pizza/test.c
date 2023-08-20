int ways(char** pizza, int pizzaSize, int k) {
    int m = pizzaSize, n = strlen(pizza[0]), mod = 1e9 + 7;
    int apples[m + 1][n + 1];
    int dp[k + 1][m + 1][n + 1];
    memset(apples, 0, sizeof(apples));
    memset(dp, 0, sizeof(dp));
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            apples[i][j] = apples[i][j + 1] + apples[i + 1][j] - apples[i + 1][j + 1] + (pizza[i][j] == 'A');
            dp[1][i][j] = (apples[i][j] > 0 ? 1 : 0);
        }
    }
    for (int ki = 2; ki <= k; ki++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[ki][i][j] = 0;
                for (int i2 = i + 1; i2 < m; i2++) {
                    if (apples[i][j] > apples[i2][j]) {
                        dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i2][j]) % mod;
                    }
                }
                for (int j2 = j + 1; j2 < n; j2++) {
                    if (apples[i][j] > apples[i][j2]) {
                        dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i][j2]) % mod;
                    }
                }
            }
        }
    }
    return dp[k][0][0];
}