int cmp(int** p, int** q) {
    return p[0][0] - q[0][0];
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 1) {
        return 0;
    }
    int ret = 0;
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            ret++;
            intervals[i][1] = fmin(intervals[i - 1][1], intervals[i][1]);
        }
    }
    return ret;
}