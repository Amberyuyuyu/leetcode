

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize;
    int n = *matrixColSize;
    if (m == 0 || n == 0) {
        return false;
    }
    int i = 0;
    int j = n - 1;
    while (i < m && j >= 0) {
        if (matrix[i][j] == target) {
            return true;
        }
        else if (matrix[i][j] < target) {
            i++;
        }
        else {
            j--;
        }
    }
    return false;
}