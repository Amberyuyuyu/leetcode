/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* circularGameLosers(int n, int k, int* returnSize) {
    int arr[n];
    memset(arr, 0, sizeof(arr));
    for (int i = k, j = 0; !arr[j]; i += k) {
        arr[j] = 1;
        j = (j + i) % n;
    }
    int* ret = (int*)calloc(n, sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < n; i++) {
        if (!arr[i]) {
            ret[(*returnSize)++] = i + 1;
        }
    }
    return ret;
}