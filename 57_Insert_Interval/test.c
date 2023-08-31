/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int left = newInterval[0];
    int right = newInterval[1];
    bool placed = false;
    int** ret = (int**)malloc(sizeof(int*) * (intervalsSize + 1));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (intervalsSize + 1));
    for (int i = 0; i < intervalsSize; i++) {
        int* interval = intervals[i];
        if (interval[0] > right) {
            if (!placed) {
                int* tmp = (int*)malloc(sizeof(int) * 2);
                tmp[0] = left;
                tmp[1] = right;
                (*returnColumnSizes)[*returnSize] = 2;
                ret[(*returnSize)++] = tmp;
                placed = true;
            }
            int* tmp = malloc(sizeof(int) * 2);
            memcpy(tmp, interval, sizeof(int) * 2);
            (*returnColumnSizes)[*returnSize] = 2;
            ret[(*returnSize)++] = tmp;
        }
        else if (interval[1] < left) {
            int* tmp = malloc(sizeof(int) * 2);
            memcpy(tmp, interval, sizeof(int) * 2);
            (*returnColumnSizes)[*returnSize] = 2;
            ret[(*returnSize)++] = tmp;
        }
        else {
            left = fmin(left, interval[0]);
            right = fmax(right, interval[1]);
        }
    }
    if (!placed) {
        int* tmp = malloc(sizeof(int) * 2);
        tmp[0] = left, tmp[1] = right;
        (*returnColumnSizes)[*returnSize] = 2;
        ret[(*returnSize)++] = tmp;
    }
    return ret;
}