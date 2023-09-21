int jump(int* nums, int numsSize) {
    if (numsSize == 1) {
        return 0;
    }
    int cur = 0;
    int next = 0;
    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        next = fmax(next, i + nums[i]);
        if (i == cur) {
            if (cur != numsSize - 1) {
                ret++;
                cur = next;
                if (cur >= numsSize - 1) {
                    break;
                }
            }
            else {
                break;
            }
        }
    }
    return ret;
}