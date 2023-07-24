int numJewelsInStones(char* jewels, char* stones) {
    int count = 0;
    int arr[58] = { 0 };
    while (*jewels) {
        arr[*jewels - 65] = 1;
        jewels++;
    }
    while (*stones) {
        if (arr[*stones - 65]) {
            count++;
        }
        stones++;
    }
    return count;

}