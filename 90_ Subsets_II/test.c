/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* path;
int pathTop;
int** ans;
int ansTop;
int* ansSize;
int cmp(void* p, void* q) {
    return *(int*)p - *(int*)q;
}
void copy() {
    int* temp = (int*)malloc(sizeof(int) * pathTop);
    for (int i = 0; i < pathTop; i++) {
        temp[i] = path[i];
    }
    ans[ansTop] = temp;
    ansSize[ansTop++] = pathTop;
}
void backtracking(int* nums, int numsSize, int startIndex, int* used) {
    copy();
    if (startIndex >= numsSize) {
        return;
    }
    for (int i = startIndex; i < numsSize; i++) {
        if (i > startIndex && nums[i] == nums[i - 1] && used[i - 1] == false) {
            continue;
        }
        path[pathTop++] = nums[i];
        used[i] = true;
        backtracking(nums, numsSize, i + 1, used);
        used[i] = false;
        pathTop--;
    }
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    path = (int*)malloc(sizeof(int) * numsSize);
    ans = (int**)malloc(sizeof(int*) * 1500);
    ansSize = (int*)malloc(sizeof(int) * 1500);
    pathTop = ansTop = 0;
    int* used = (int*)malloc(sizeof(int) * numsSize);
    qsort(nums, numsSize, sizeof(int), cmp);
    backtracking(nums, numsSize, 0, used);
    *returnSize = ansTop;
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    for (int i = 0; i < ansTop; i++) {
        (*returnColumnSizes)[i] = ansSize[i];
    }

    return ans;
}