int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] >= 1 && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1]) {
            int tmp = nums[i];
            nums[i] = nums[tmp - 1];
            nums[tmp - 1] = tmp;
        }
    }
    int ans = numsSize + 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            ans = i + 1;
            break;
        }
    }
    return ans;
}