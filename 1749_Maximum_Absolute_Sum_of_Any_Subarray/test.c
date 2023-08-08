int maxAbsoluteSum(int* nums, int numsSize) {
    int min = 0;
    int max = 0;
    int maxSum = 0;
    int minSum = 0;
    for (int i = 0; i < numsSize; i++) {
        max += nums[i];
        maxSum = fmax(maxSum, max);
        max = fmax(0, max);
        min += nums[i];
        minSum = fmin(minSum, min);
        min = fmin(0, min);
    }

    return fmax(maxSum, abs(minSum));

}