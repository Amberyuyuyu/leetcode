int cmp(int** p, int** q) {
    return p[0][0] > q[0][0] ? 1 : -1;
}
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize == 0) {
        return 0;
    }
    qsort(points, pointsSize, sizeof(int*), cmp);
    int ret = 1;
    for (int i = 1; i < pointsSize; i++) {
        if (points[i - 1][1] < points[i][0]) {
            ret++;
        }
        else {
            points[i][1] = fmin(points[i - 1][1], points[i][1]);
        }
    }
    return ret;
}