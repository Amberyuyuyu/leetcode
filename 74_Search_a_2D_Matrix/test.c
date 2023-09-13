bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize;
    int n = *matrixColSize;
    int left = 0;
    int right = m * n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int num = matrix[mid / n][mid % n];
        if (num > target) {
            right = mid - 1;
        }
        else if (num < target) {
            left = mid + 1;
        }
        else {
            return true;
        }
    }
    return false;
}