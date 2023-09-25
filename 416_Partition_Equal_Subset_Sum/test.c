int get_sum(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    return sum;
}
bool canPartition(int* nums, int numsSize) {
    int sum = get_sum(nums, numsSize);
    if (sum % 2) {
        return false;
    }
    int target = sum / 2;
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = fmax(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    return dp[target] == target;
}