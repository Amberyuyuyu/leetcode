/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** ret = (char**)malloc(sizeof(char*) * numsSize);
    *returnSize = 0;
    int i = 0;
    while (i < numsSize) {
        int start = i;
        i++;
        while (i < numsSize && nums[i] == nums[i - 1] + 1) {
            i++;
        }
        int end = i - 1;
        char* temp = malloc(sizeof(char) * 42);
        sprintf(temp, "%d", nums[start]);
        if (start < end) {
            sprintf(temp + strlen(temp), "->");
            sprintf(temp + strlen(temp), "%d", nums[end]);
        }
        ret[(*returnSize)++] = temp;
    }
    return ret;
}