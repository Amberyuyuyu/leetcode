int countServers(int** grid, int gridSize, int* gridColSize) {
    int cnt[gridSize][*gridColSize];
    memset(cnt, 0, sizeof(cnt));
    int ret = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                int count = 0;
                for (int m = 0; m < gridSize; m++) {
                    count += grid[m][j];
                }
                for (int n = 0; n < *gridColSize; n++) {
                    count += grid[i][n];
                }
                cnt[i][j] = count - 1;
                if (cnt[i][j] >= 2) {
                    ret++;
                }
            }
        }
    }
    return ret;
}