/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = 0;
    if (*matrixColSize == 0 || matrixSize == 0) {
        return NULL;
    }
    int m = matrixSize;
    int n = *matrixColSize;
    int* ret = (int*)malloc(sizeof(int) * (m * n));
    int squre = fmin(m / 2, n / 2);
    int startx = 0;
    int starty = 0;
    for (int offset = 1; offset <= squre; offset++) {
        for (int j = starty; j < n - offset; j++) {
            ret[(*returnSize)++] = matrix[startx][j];
        }
        for (int i = startx; i < m - offset; i++) {
            ret[(*returnSize)++] = matrix[i][n - offset];
        }
        for (int j = n - offset; j > starty; j--) {
            ret[(*returnSize)++] = matrix[m - offset][j];
        }
        for (int i = m - offset; i > startx; i--) {
            ret[(*returnSize)++] = matrix[i][starty];
        }
        startx += 1;
        starty += 1;
    }
    int min_num = fmin(m, n);
    if (min_num % 2 == 1) {
        if (m < n) {
            for (int j = squre; j < n - squre; j++) {
                ret[(*returnSize)++] = matrix[squre][j];
            }
        }
        else {
            for (int i = squre; i < m - squre; i++) {
                ret[(*returnSize)++] = matrix[i][squre];
            }
        }
    }
    return ret;
}