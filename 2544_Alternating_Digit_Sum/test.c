int alternateDigitSum(int n) {
    int arr[10] = { 0 };
    int len = 0;
    while (n) {
        arr[len] = n % 10;
        len++;
        n = n / 10;
    }
    int flag = 1;
    if (len % 2 == 0) {
        flag = -1;
    }
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += flag * arr[i];
        flag = -flag;
    }
    return sum;
}