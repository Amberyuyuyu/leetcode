/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(int** a, int** b) {
    return a[0][0] > b[0][0];
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    int** ret = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);

    for (int i = 0; i < intervalsSize; i++) {
        ret[i] = malloc(sizeof(int) * 2);
        returnColumnSizes[0][i] = 2;
    }
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    int count = 0;
    for (int i = 0; i < intervalsSize; i++) {
        if (i == 0 || i > 0 && intervals[i][0] > ret[count - 1][1]) {
            ret[count++] = intervals[i];
        }
        else {
            ret[count - 1][1] = fmax(ret[count - 1][1], intervals[i][1]);
        }
    }
    *returnSize = count;
    return ret;
}