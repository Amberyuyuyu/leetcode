int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    int dp[matrixSize][*matrixColSize];
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            dp[i][j] = 0;
        }
    }
    for (int j = 0; j < *matrixColSize; j++) {
        dp[0][j] = matrix[0][j];
    }
    for (int i = 1; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (j == 0) {
                dp[i][j] = matrix[i][j] + fmin(dp[i - 1][j], dp[i - 1][j + 1]);
            }
            if (j > 0 && j < *matrixColSize - 1) {
                int tmp = fmin(dp[i - 1][j], dp[i - 1][j - 1]);
                dp[i][j] = matrix[i][j] + fmin(tmp, dp[i - 1][j + 1]);
            }
            if (j == *matrixColSize - 1) {
                dp[i][j] = matrix[i][j] + fmin(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }
    int minSum = 100000;
    for (int j = 0; j < *matrixColSize; j++) {
        if (dp[matrixSize - 1][j] < minSum) {
            minSum = dp[matrixSize - 1][j];
        }
    }
    return minSum;
}