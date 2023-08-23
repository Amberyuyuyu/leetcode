bool is_blue(int* nums, int numsSize, int target, int i) {
    int end = nums[numsSize - 1];
    if (nums[i] > end) {
        return target > end && nums[i] >= target;
    }
    else {
        return target > end || nums[i] >= target;
    }
}

int search(int* nums, int numsSize, int target) {
    int left = -1;
    int right = numsSize;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (is_blue(nums, numsSize, target, mid)) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    if (right == numsSize || nums[right] != target) {
        return -1;
    }
    return right;

}