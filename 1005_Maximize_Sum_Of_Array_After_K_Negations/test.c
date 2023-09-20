#define abs(x) (((x)>0) ? (x) : (-x))
int cmp(const void* p, const void* q) {
    return abs(*(int*)q) - abs(*(int*)p);
}
int sum(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    return sum;
}
int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0 && k>0) {
            nums[i] *= -1;
            k--;
        }
    }
    if (k % 2 == 1) {
        nums[numsSize - 1] *= -1;
    }
    return sum(nums, numsSize);
}