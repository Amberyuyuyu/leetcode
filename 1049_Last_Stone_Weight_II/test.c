int get_sum(int* stones, int stonesSize) {
    int sum = 0;
    for (int i = 0; i < stonesSize; i++) {
        sum += stones[i];
    }
    return sum;
}

int lastStoneWeightII(int* stones, int stonesSize) {
    int sum = get_sum(stones, stonesSize);
    int target = sum / 2;
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < stonesSize; i++) {
        for (int j = target; j >= stones[i]; j--) {
            dp[j] = fmax(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    return sum - dp[target] - dp[target];
}