int diagonalSum(int** mat, int matSize, int* matColSize) {
    int sum = 0;
    for (int i = 0; i < matSize; i++) {
        sum += mat[i][i];
        if (i == matSize - i - 1) {
            continue;
        }
        sum += mat[matSize - 1 - i][i];
    }

    return sum;
}