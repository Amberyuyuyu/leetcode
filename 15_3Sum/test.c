/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void* p1, const void* p2) {
    return (*(int*)p1 - *(int*)p2);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** ret = (int**)malloc(sizeof(int*) * 100000);
    if (numsSize < 3) {
        *returnSize = 0;
        return ret;
    }
    int count = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 2; i++) {
        if (nums[i] > 0) {
            break;
        }
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = numsSize - 1;
        int sum = 0;
        while (left < right) {
            sum = nums[i] + nums[left] + nums[right];
            if (sum < 0) {
                left++;
            }
            else if (sum > 0) {
                right--;
            }
            else {
                int* arr = (int*)malloc(sizeof(int) * 3);
                arr[0] = nums[i];
                arr[1] = nums[left];
                arr[2] = nums[right];
                ret[count++] = arr;
                while (right > left && nums[right] == nums[right - 1]) {
                    right--;
                }
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                left++;
                right--;
            }
        }
    }
    *returnSize = count;
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    int z = 0;
    for (z = 0; z < count; z++) {
        (*returnColumnSizes)[z] = 3;
    }
    return ret;
}