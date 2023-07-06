/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* maximumEvenSplit(long long finalSum, int* returnSize) {
    *returnSize = 0;
    if (finalSum % 2 != 0) {
        return NULL;
    }
    long long i = 2;
    long long* arr = (long long*)malloc(sizeof(long long) * sqrt(finalSum));
    for (i = 2; i <= finalSum; i += 2) {
        arr[(*returnSize)++] = i;
        finalSum -= i;
    }
    arr[(*returnSize) - 1] += finalSum;

    return arr;
}