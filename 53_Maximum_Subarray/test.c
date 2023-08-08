int maxSubArray(int* nums, int numsSize) {
    int pre = 0;
    int maxSum = nums[0];
    for (int i = 0; i < numsSize; i++) {
        pre = fmax(nums[i], pre + nums[i]);
        maxSum = fmax(maxSum, pre);
    }
    return maxSum;
}