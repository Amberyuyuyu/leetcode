void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int row[matrixSize];
    int col[*matrixColSize];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    int i = 0;
    int j = 0;
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            if (!matrix[i][j]) {
                col[j] = row[i] = 1;
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            if (col[j] == 1 || row[i] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}