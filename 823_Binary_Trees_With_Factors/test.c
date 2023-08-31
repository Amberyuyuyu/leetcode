int cmp(void* p, void* q) {
    return *(int*)p - *(int*)q;
}

int numFactoredBinaryTrees(int* arr, int arrSize) {
    long long* dp = (long long*)malloc(sizeof(long long) * arrSize);
    long long ret = 0, mod = 1e9 + 7;
    qsort(arr, arrSize, sizeof(int), cmp);
    for (long long i = 0; i < arrSize; i++) {
        dp[i] = 1;
        for (long long left = 0, right = i - 1; left <= right; left++) {
            while (left <= right && (long long)arr[left] * arr[right] > arr[i]) {
                right--;
            }
            if (left <= right && (long long)arr[left] * arr[right] == arr[i]) {
                if (left == right) {
                    dp[i] = (dp[i] + dp[left] * dp[right]) % mod;
                }
                else {
                    dp[i] = (dp[i] + dp[left] * dp[right] * 2) % mod;
                }
            }
        }
        ret = (ret + dp[i]) % mod;
    }
    return ret;
}