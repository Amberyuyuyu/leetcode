int dfs(int i, int j, int n, int** grid, int r, int c) {
    if (grid[i][j] == 2) {
        if (n == 0) {
            return 1;
        }
        return 0;
    }
    int t = grid[i][j];
    int ret = 0;

    grid[i][j] = -1;
    int choices[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
    for (int k = 0; k < 4; k++) {
        int ni = i + choices[k][0];
        int nj = j + choices[k][1];
        if (ni >= 0 && ni < r && nj >= 0 && nj < c && (grid[ni][nj] == 0 || grid[ni][nj] == 2)) {
            ret += dfs(ni, nj, n - 1, grid, r, c);
        }
    }
    grid[i][j] = t;
    return ret;
}

int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {
    int r = gridSize;
    int c = *gridColSize;
    int n = 0;
    int si = 0;
    int sj = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 0) {
                n++;
            }
            else if (grid[i][j] == 1) {
                n++;
                si = i;
                sj = j;
            }
        }
    }
    return dfs(si, sj, n, grid, r, c);
}