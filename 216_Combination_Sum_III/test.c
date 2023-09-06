

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* path;
int** ans;
int ansTop;
int pathTop;

void backtracking(int targetSum, int k, int sum, int startIndex) {
    if (pathTop == k) {
        if (sum == targetSum) {
            int* temp = (int*)malloc(sizeof(int) * k);
            for (int j = 0; j < k; j++) {
                temp[j] = path[j];
            }
            ans[ansTop++] = temp;
        }
        return;
    }
    for (int i = startIndex; i <= 9; i++) {
        sum += i;
        path[pathTop++] = i;
        backtracking(targetSum, k, sum, i + 1);
        sum -= i;
        pathTop--;
    }

}
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    path = (int*)malloc(sizeof(int) * k);
    ans = (int**)malloc(sizeof(int*) * 20);
    pathTop = ansTop = 0;
    backtracking(n, k, 0, 1);
    *returnSize = ansTop;
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    for (int i = 0; i < ansTop; i++) {
        (*returnColumnSizes)[i] = k;
    }
    return ans;
}