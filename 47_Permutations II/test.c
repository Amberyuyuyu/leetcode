

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* path;
int pathTop;
int** ans;
int ansTop;
int cmp(void* p, void* q) {
    return *(int*)p - *(int*)q;
}
void copy() {
    int* temp = (int*)malloc(sizeof(int) * pathTop);
    memcpy(temp, path, pathTop * sizeof(int));
    ans[ansTop++] = temp;
}
void backtracking(int* nums, int numsSize, int* used) {
    if (pathTop == numsSize) {
        copy();
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (used[i] || (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)) {
            continue;
        }
        path[pathTop++] = nums[i];
        used[i] = 1;
        backtracking(nums, numsSize, used);
        pathTop--;
        used[i] = 0;
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    path = (int*)malloc(sizeof(int) * numsSize);
    ans = (int**)malloc(sizeof(int*) * 1000);
    ansTop = pathTop = 0;
    int* used = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        used[i] = 0;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    backtracking(nums, numsSize, used);
    *returnSize = ansTop;
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    for (int i = 0; i < ansTop; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return ans;
}