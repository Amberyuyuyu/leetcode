/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** result;
int resultTop;
int segments[3];
int isValid(char* s, int start, int end) {
    if (start > end) {
        return 0;
    }
    if (s[start] == '0' && start != end) {
        return 0;
    }
    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] > '9' || s[i] < '0') {
            return 0;
        }
        num = num * 10 + (s[i] - '0');
        if (num > 255) {
            return 0;
        }
    }
    return 1;
}
void backtracking(char* s, int startIndex, int pointNum) {
    if (pointNum == 3) {
        if (isValid(s, startIndex, strlen(s) - 1)) {
            char* temp = (char*)malloc(sizeof(char) * (strlen(s) + 4));
            int count = 0;
            int count1 = 0;
            for (int j = 0; j < strlen(s); j++) {
                temp[count++] = s[j];
                if (count1 < 3 && j == segments[count1]) {
                    temp[count++] = '.';
                    count1++;
                }
            }
            temp[count] = 0;
            result = (char**)realloc(result, sizeof(char*) * (resultTop + 1));
            result[resultTop++] = temp;
        }
        return;
    }
    for (int i = startIndex; i < strlen(s); i++) {
        if (isValid(s, startIndex, i)) {
            segments[pointNum] = i;
            backtracking(s, i + 1, pointNum + 1);
        }
        else {
            break;
        }
    }
}
char** restoreIpAddresses(char* s, int* returnSize) {
    result = (char**)malloc(0);
    resultTop = 0;
    backtracking(s, 0, 0);
    *returnSize = resultTop;
    return result;
}