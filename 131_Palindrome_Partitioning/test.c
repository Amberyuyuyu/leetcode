/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** path;
int pathTop = 0;
char*** ans;
int ansTop = 0;
int* ansSize;

int isPalindrome(const char* str, int startIndex, int endIndex) {
    while (startIndex <= endIndex) {
        if (str[endIndex--] != str[startIndex++]) {
            return 0;
        }
    }
    return 1;
}
void copy() {
    char** tempPath = (char**)malloc(sizeof(char*) * pathTop);
    for (int i = 0; i < pathTop; i++) {
        tempPath[i] = path[i];
    }
    ans[ansTop] = tempPath;
    ansSize[ansTop++] = pathTop;
}
char* cutString(char* str, int startIndex, int endIndex) {
    char* tempString = (char*)malloc(sizeof(char) * (endIndex - startIndex + 2));
    int index = 0;
    for (int i = startIndex; i <= endIndex; i++) {
        tempString[index++] = str[i];
    }
    tempString[index] = '\0';
    return tempString;
}
void backtracking(const char* str, int strlen, int startIndex) {
    if (startIndex >= strlen) {
        copy();
        return;
    }
    for (int i = startIndex; i < strlen; i++) {
        if (isPalindrome(str, startIndex, i)) {
            path[pathTop++] = cutString(str, startIndex, i);
        }
        else {
            continue;
        }
        backtracking(str, strlen, i + 1);
        pathTop--;
    }
}
char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int strLen = strlen(s);
    path = (char**)malloc(sizeof(char*) * strLen);
    ans = (char***)malloc(sizeof(char**) * 40000);
    ansSize = (int*)malloc(sizeof(int) * 40000);
    ansTop = pathTop = 0;
    backtracking(s, strLen, 0);

    *returnSize = ansTop;
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    for (int i = 0; i < ansTop; i++) {
        (*returnColumnSizes)[i] = ansSize[i];
    }
    return ans;
}