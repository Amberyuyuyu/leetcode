int cmp(void* p1, void* p2) {
    return (*(int*)p1 - *(int*)p2);
}
int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int ret = nums[0] + nums[1] + nums[2];
    int minsum = abs(ret - target);
    if (numsSize == 3) {
        return ret;
    }
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                return target;
            }
            else if (sum < target) {
                while (left < right && nums[left] == nums[++left]) {}
            }
            else {
                while (left < right && nums[right] == nums[--right]) {}
            }
            if (abs(sum - target) < minsum) {
                minsum = abs(sum - target);
                ret = sum;
            }
        }
    }
    return ret;
}