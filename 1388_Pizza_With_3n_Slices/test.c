int calculate(const int* slices, int slicesSize) {
    int i = 0;
    int j = 0;
    int k = (slicesSize + 1) / 3;
    int dp[slicesSize][k + 1];
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < slicesSize; i++) {
        dp[i][1] = slices[i];
        if (i > 0) {
            dp[i][1] = fmax(slices[i], dp[i - 1][1]);
            for (j = 2; j <= k; j++) {
                if (i >= 2) {
                    dp[i][j] = fmax(dp[i - 1][j], dp[i - 2][j - 1] + slices[i]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
    }
    return dp[slicesSize - 1][k];
}
int maxSizeSlices(int* slices, int slicesSize) {
    return fmax(calculate(slices, slicesSize - 1), calculate(slices + 1, slicesSize - 1));
}