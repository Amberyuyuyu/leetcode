

int wiggleMaxLength(int* nums, int numsSize) {
    int ret = 1;
    if (numsSize == 1) {
        return ret;
    }
    int prediff = 0;
    int curdiff = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        curdiff = nums[i + 1] - nums[i];
        if (prediff >= 0 && curdiff < 0 || prediff <= 0 && curdiff>0) {
            ret++;
            prediff = curdiff;
        }

    }
    return ret;
}