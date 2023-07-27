int cmp(void* p, void* q) {
    return *(int*)p - *(int*)q;
}
int deleteGreatestValue(int** grid, int gridSize, int* gridColSize) {
    for (int i = 0; i < gridSize; i++) {
        qsort(grid[i], *gridColSize, sizeof(int), cmp);
    }
    int sum = 0;
    for (int j = 0; j < *gridColSize; j++) {
        int max = 0;
        for (int i = 0; i < gridSize; i++) {
            if (grid[i][j] > max) {
                max = grid[i][j];
            }
        }
        sum += max;
    }
    return sum;
}