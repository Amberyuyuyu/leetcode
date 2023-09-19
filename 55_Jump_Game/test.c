bool canJump(int* nums, int numsSize) {
    int cover = 0;
    for (int i = 0; i <= cover; i++) {
        cover = fmax(cover, i + nums[i]);
        if (cover >= numsSize - 1) {
            return true;
        }
    }
    return false;
}