int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int curSum = 0;
    int totalSum = 0;
    int start = 0;
    for (int i = 0; i < gasSize; i++) {
        int diff = gas[i] - cost[i];
        curSum += diff;
        totalSum += diff;
        if (curSum < 0) {
            curSum = 0;
            start = i + 1;
        }
    }
    if (totalSum < 0) {
        return -1;
    }
    return start;
}