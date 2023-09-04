/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* path;
int pathTop;
int** ans;
int ansTop;
void backtracking(int n, int k, int startIndex) {
    if (pathTop == k) {
        int* temp = (int*)malloc(sizeof(int) * k);
        int i;
        for (i = 0; i < k; i++) {
            temp[i] = path[i];
        }
        ans[ansTop++] = temp;
        return;
    }
    int j;
    for (j = startIndex; j <= n - (k - pathTop) + 1; j++) {
        path[pathTop++] = j;
        backtracking(n, k, j + 1);
        pathTop--;
    }
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    path = (int*)malloc(sizeof(int) * k);
    ans = (int**)malloc(sizeof(int*) * 1000000);
    pathTop = ansTop = 0;
    backtracking(n, k, 1);
    *returnSize = ansTop;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    int i;
    for (i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = k;
    }
    return ans;
}