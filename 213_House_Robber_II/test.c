int robRange(int* nums, int start, int end) {
    int slow = nums[start];
    int fast = fmax(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; i++) {
        int tmp = fast;
        fast = fmax(slow + nums[i], fast);
        slow = tmp;
    }
    return fast;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }
    else if (numsSize == 2) {
        return fmax(nums[0], nums[1]);
    }
    return fmax(robRange(nums, 0, numsSize - 2), robRange(nums, 1, numsSize - 1));
}