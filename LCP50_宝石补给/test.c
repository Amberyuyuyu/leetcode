int giveGem(int* gem, int gemSize, int** operations, int operationsSize, int* operationsColSize) {
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < operationsSize; i++) {
        int index1 = operations[i][0];
        int index2 = operations[i][1];
        int num = gem[index1] / 2;
        gem[index1] -= num;
        gem[index2] += num;
    }
    for (int i = 0; i < gemSize; i++) {
        if (gem[i] < min) {
            min = gem[i];
        }
        if (gem[i] > max) {
            max = gem[i];
        }
    }
    return max - min;
}