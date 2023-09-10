/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* path;
int pathTop;
int** ans;
int* ansSize;
int ansTop;
int cmp(void* p, void* q) {
    return *(int*)p - *(int*)q;
}
void backtracking(int* candidates, int candidatesSize, int target, int index, int sum) {
    if (sum >= target) {
        if (sum == target) {
            int* temp = (int*)malloc(sizeof(int) * pathTop);
            for (int i = 0; i < pathTop; i++) {
                temp[i] = path[i];
            }
            ans[ansTop] = temp;
            ansSize[ansTop++] = pathTop;
        }
        return;
    }
    for (int i = index; i < candidatesSize; i++) {
        if (i > index && candidates[i] == candidates[i - 1]) {
            continue;
        }
        path[pathTop++] = candidates[i];
        sum += candidates[i];
        backtracking(candidates, candidatesSize, target, i + 1, sum);
        sum -= candidates[i];
        pathTop--;
    }
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    path = (int*)malloc(sizeof(int) * 40);
    ans = (int**)malloc(sizeof(int*) * 200);
    ansSize = (int*)malloc(sizeof(int) * 200);
    pathTop = ansTop = 0;
    backtracking(candidates, candidatesSize, target, 0, 0);
    *returnSize = ansTop;
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    for (int i = 0; i < ansTop; i++) {
        (*returnColumnSizes)[i] = ansSize[i];
    }

    return ans;
}