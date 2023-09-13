

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* path;
int pathTop;
int** ans;
int ansTop;
void copy() {
    int* temp = (int*)malloc(sizeof(int) * pathTop);
    memcpy(temp, path, sizeof(int) * pathTop);
    ans[ansTop++] = temp;
}

void backtracking(int* nums, int numsSize, int* used) {
    if (pathTop == numsSize) {
        copy();
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) {
            continue;
        }
        path[pathTop++] = nums[i];
        used[i] = 1;
        backtracking(nums, numsSize, used);
        pathTop--;
        used[i] = 0;
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    path = (int*)malloc(sizeof(int) * numsSize);
    ans = (int**)malloc(sizeof(int*) * 720);
    ansTop = pathTop = 0;
    int* used = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        used[i] = 0;
    }
    backtracking(nums, numsSize, used);
    *returnSize = ansTop;
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    for (int i = 0; i < ansTop; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return ans;
}
