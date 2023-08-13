/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    for (int i = 0, j = numsSize - 1, pos = numsSize - 1; i <= j; ) {
        if (nums[i] * nums[i] > nums[j] * nums[j]) {
            ret[pos--] = nums[i] * nums[i++];
        }
        else {
            ret[pos--] = nums[j] * nums[j--];
        }
    }
    return ret;
}