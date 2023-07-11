long long maxAlternatingSum(int* nums, int numsSize) {
    long ret = nums[0];
    for (int i = 1; i < numsSize; i++) {
        ret += fmax(0, nums[i] - nums[i - 1]);
    }

    return ret;
}