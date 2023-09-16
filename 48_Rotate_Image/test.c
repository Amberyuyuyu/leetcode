

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = *matrixColSize;
    for (int i = 0; i < m; i++) {
        for (int j = i; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    int left = 0;
    int right = n - 1;
    while (left < right) {
        for (int i = 0; i < m; i++) {
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
        }
        left++;
        right--;
    }
}