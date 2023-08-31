/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    int left = 1;
    int right = 1;
    for (int i = 0; i < numsSize; i++) {
        ret[i] = 1;
    }
    for (int i = 1; i < numsSize; i++) {
        left *= nums[i - 1];
        ret[i] *= left;
        right *= nums[numsSize - i];
        ret[numsSize - i - 1] *= right;
    }
    *returnSize = numsSize;
    return ret;
}