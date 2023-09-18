

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 1430
char* str;
char** ret;
void generate(int left, int right, int n, int index, int* returnSize) {
    if (index == 2 * n) {
        ret[*returnSize] = (char*)calloc(2 * n + 1, sizeof(char));
        strcpy(ret[(*returnSize)++], str);
        return;
    }
    if (left < n) {
        str[index] = '(';
        generate(left + 1, right, n, index + 1, returnSize);
    }
    if (right < left) {
        str[index] = ')';
        generate(left, right + 1, n, index + 1, returnSize);
    }
}
char** generateParenthesis(int n, int* returnSize) {
    ret = (int**)malloc(sizeof(char*) * MAX_SIZE);
    str = (char*)calloc(2 * n + 1, sizeof(char));
    *returnSize = 0;
    int left = 0;
    int right = 0;
    generate(0, 0, n, 0, returnSize);
    return ret;
}