int rob(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }
    int dp[numsSize];
    memset(dp, 0, sizeof(dp));
    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    for (int i = 2; i < numsSize; i++) {
        dp[i] = dp[i - 1] > (dp[i - 2] + nums[i]) ? dp[i - 1] : (dp[i - 2] + nums[i]);
    }
    return dp[numsSize - 1];
}