int subtractProductAndSum(int n) {
    if (n == 0) {
        return 0;
    }
    int mul = 1;
    int sum = 0;
    int tmp = 0;
    while (n) {
        tmp = n % 10;
        mul *= tmp;
        sum += tmp;
        n /= 10;
    }

    return mul - sum;
}