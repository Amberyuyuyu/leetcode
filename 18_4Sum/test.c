/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(void* p1, void* p2) {
    return (*(int*)p1 - *(int*)p2);
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * 800);
    int* cur = nums;
    if (numsSize < 4) {
        *returnSize = 0;
        return result;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int count = 0;
    for (int k = 0; k < numsSize; k++) {
        if (nums[k] >= 0 && nums[k] > target) {
            break;
        }
        if (k > 0 && nums[k] == nums[k - 1]) {
            continue;
        }

        for (int i = k + 1; i < numsSize; i++) {
            if (nums[i] + nums[k] >= 0 && nums[i] + nums[k] > target) {
                break;
            }
            if (i > k + 1 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = numsSize - 1;
            while (left < right) {
                long sum = nums[i] + nums[k];
                sum += nums[left];
                sum += nums[right];
                if (sum > target) {
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    int* ans = (int*)malloc(sizeof(int) * 4);
                    ans[0] = nums[k];
                    ans[1] = nums[i];
                    ans[2] = nums[left];
                    ans[3] = nums[right];
                    result[count++] = ans;
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    right--;
                    left++;
                }
            }
        }
    }
    *returnSize = count;
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    int z = 0;
    for (z = 0; z < count; z++) {
        (*returnColumnSizes)[z] = 4;
    }
    return result;
}