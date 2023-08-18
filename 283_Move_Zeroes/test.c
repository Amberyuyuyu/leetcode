void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;

}
void moveZeroes(int* nums, int numsSize) {
    int slow = 0;
    int fast = 0;
    while (fast < numsSize) {
        if (nums[fast]) {
            swap(&nums[slow], &nums[fast]);
            slow++;
        }
        fast++;
    }

}