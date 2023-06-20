
int* singleNumbers(int* nums, int numsSize, int* returnSize) {
    int sum = 0;
    int* arr = (int*)calloc(2, sizeof(int));
    int num1 = 0, num2 = 0;
    for (int i = 0; i < numsSize; i++) {
        sum ^= nums[i];
    }
    int pos = 0;
    for (int i = 0; i < 32; i++) {
        if ((sum >> i) & 1 == 1) {
            pos = i;
            break;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] >> pos) & 1 == 1) {
            num1 ^= nums[i];
        }
        else {
            num2 ^= nums[i];
        }
    }
    arr[0] = num1;
    arr[1] = num2;
    *returnSize = 2;
    return arr;
}