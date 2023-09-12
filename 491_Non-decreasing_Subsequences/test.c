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
void copy() {
    int* temp = (int*)malloc(sizeof(int) * pathTop);
    for (int i = 0; i < pathTop; i++) {
        temp[i] = path[i];
    }
    ans[ansTop] = temp;
    ansSize[ansTop++] = pathTop;
}
int find(int* uset, int usetSize, int key) {
    for (int i = 0; i < usetSize; i++) {
        if (uset[i] == key) {
            return 1;
        }
    }
    return 0;
}
void backtracking(int* nums, int numsSize, int startIndex) {
    if (pathTop > 1) {
        copy();
    }
    int* uset = (int*)malloc(sizeof(int) * numsSize);
    int usetTop = 0;
    for (int i = startIndex; i < numsSize; i++) {
        if ((pathTop > 0 && nums[i] < path[pathTop - 1]) || find(uset, usetTop, nums[i])) {
            continue;
        }
        uset[usetTop++] = nums[i];
        path[pathTop++] = nums[i];
        backtracking(nums, numsSize, i + 1);
        pathTop--;
    }
}
int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    path = (int*)malloc(sizeof(int) * numsSize);
    ans = (int**)malloc(sizeof(int*) * 32768);
    ansSize = (int*)malloc(sizeof(int) * 32768);
    pathTop = ansTop = 0;
    backtracking(nums, numsSize, 0);

    *returnSize = ansTop;
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    for (int i = 0; i < ansTop; i++) {
        (*returnColumnSizes)[i] = ansSize[i];
    }
    return ans;
}