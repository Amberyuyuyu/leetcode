void itoa(int num, char* str, int* strSize) {
    *strSize = 0;
    while (num) {
        str[(*strSize)++] = num % 10 + '0';
        num /= 10;
    }
    char temp;
    int left = 0;
    int right = *strSize - 1;
    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int monotoneIncreasingDigits(int n) {
    if (n == 0) {
        return 0;
    }
    int strSize = 0;
    char strN[11];
    itoa(n, strN, &strSize);
    int flag = strSize;
    for (int i = strSize - 1; i > 0; i--) {
        if (strN[i - 1] > strN[i]) {
            flag = i;
            strN[i - 1]--;
        }
    }
    for (int i = flag; i < strSize; i++) {
        strN[i] = '9';
    }
    return atoi(strN);
}