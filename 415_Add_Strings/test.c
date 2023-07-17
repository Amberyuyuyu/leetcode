char* addStrings(char* num1, char* num2) {
    if (num1 == NULL) {
        return num2;
    }
    if (num2 == NULL) {
        return num1;
    }
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int i = len1 - 1;
    int j = len2 - 1;
    char* ret = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
    int count = 0;
    int flag = 0;
    int sum = 0;
    // while(i>=0 || j>=0 || flag){
    //     int x = i>=0 ? num1[i]-'0' : 0;
    //     int y = j>=0 ? num2[j]-'0' : 0;
    //     sum = x+y+flag;
    //     ret[count++] = '0'+sum%10;
    //     flag = sum/10;
    //     i--;
    //     j--;
    // }
    // while (i >= 0 && j >= 0) {
    //     int x = num1[i] - '0';
    //     int y = num2[j] - '0';
    //     int sum = x + y + flag;
    //     ret[count++] = '0' + sum%10;
    //     flag = sum / 10;
    //     i--;
    //     j--;
    // }
    // if (i >= 0) {
    //     while (i >= 0) {
    //         char sum = (num1[i--] - '0') + flag;
    //         ret[count++] = '0' + sum % 10;
    //         flag = sum / 10;
    //     }
    // }
    // if (j >= 0) {
    //     while (j >= 0) {
    //         char sum = (num2[j--] - '0') + flag;
    //         ret[count++] = '0' + sum % 10;
    //         flag = sum / 10;
    //     }
    // }
    if (flag) {
        ret[count++] = '0' + flag;
    }
    for (int i = 0; i < count / 2; i++) {
        char tmp = ret[i];
        ret[i] = ret[count - i - 1];
        ret[count - i - 1] = tmp;
    }
    ret[count] = 0;
    return ret;
}