int cmp(void* p, void* q) {
    return *(int*)p - *(int*)q;
}
int sumOfPower(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int dp[numsSize], preSum[numsSize + 1];
    memset(preSum, 0, sizeof(preSum));
    int res = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < numsSize; i++) {
        dp[i] = (preSum[i] + nums[i]) % mod;
        preSum[i + 1] = (preSum[i] + dp[i]) % mod;
        res = (int)((res + (long long)nums[i] * nums[i] % mod * dp[i]) % mod);
        if (res < 0) {
            res += mod;
        }
    }
    return res;
}