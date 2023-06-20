
void rotate_right(int* nums, int left, int right) {
    while (left < right) {
        int tmp = *(nums + left);
        *(nums + left) = *(nums + right);
        *(nums + right) = tmp;
        left++;
        right--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (k >= numsSize) {
        k %= numsSize;
    }
    rotate_right(nums, 0, numsSize - k - 1);
    rotate_right(nums, numsSize - k, numsSize - 1);
    rotate_right(nums, 0, numsSize - 1);
}