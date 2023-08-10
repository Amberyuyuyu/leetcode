int minFallingPathSum(int** grid, int gridSize, int* gridColSize) {
    int ret = 0x4d58;
    int n = gridSize;
    int f[n][n];
    memset(f, 0x4d58, sizeof(f));
    for (int i = 0; i < n; i++) {
        f[0][i] = grid[0][i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j == k) {
                    continue;
                }
                f[i][j] = fmin(f[i][j], f[i - 1][k] + grid[i][j]);
            }
        }
    }

    for (int j = 0; j < n; j++) {
        ret = fmin(ret, f[n - 1][j]);
    }
    return ret;
}