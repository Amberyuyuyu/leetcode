int get_sum(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    return sum;
}
int findTargetSumWays(int* nums, int numsSize, int target) {
    int sum = get_sum(nums, numsSize);
    if (abs(target) > sum) {
        return 0;
    }
    if ((sum + target) % 2 == 1) {
        return 0;
    }
    int size = (sum + target) / 2;
    int dp[size + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = size; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }
    return dp[size];
}