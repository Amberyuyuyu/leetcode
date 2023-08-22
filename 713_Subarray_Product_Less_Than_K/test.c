int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    int ret_num = 0;
    int ret = 1;
    int left = 0;
    for (int right = 0; right < numsSize; right++) {
        if (k <= 1) {
            return 0;
        }
        ret *= nums[right];
        while (ret >= k && left < right) {
            ret /= nums[left];
            left++;
        }
        if (ret < k) {
            ret_num += right - left + 1;
        }
    }
    return ret_num;
}