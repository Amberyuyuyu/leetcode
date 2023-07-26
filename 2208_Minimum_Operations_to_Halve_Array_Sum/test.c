void Swap(double* p, double* q) {
    double tmp = *p;
    *p = *q;
    *q = tmp;
}
void AdjustDown(double* nums, int root, int numsSize) {
    int parent = root;
    int child = 2 * parent + 1;
    while (child < numsSize) {
        while (child + 1 < numsSize && nums[child + 1] > nums[child]) {
            child++;
        }
        if (nums[parent] < nums[child]) {
            Swap(&nums[parent], &nums[child]);
            parent = child;
            child = 2 * parent + 1;
        }
        else {
            break;
        }
    }
}
void HeapSort(double* nums, int numsSize) {
    for (int i = (numsSize - 1 - 1) / 2; i >= 0; i--) {
        AdjustDown(nums, i, numsSize);
    }
}
int halveArray(int* nums, int numsSize) {
    double ret[numsSize];
    double sum = 0;
    for (int i = 0; i < numsSize; i++) {
        ret[i] = nums[i];
        sum += nums[i];
    }
    HeapSort(ret, numsSize);
    sum /= 2;
    int count = 0;
    while (sum > 0) {
        sum -= ret[0] / 2;
        ret[0] /= 2;
        count++;
        AdjustDown(ret, 0, numsSize);
    }
    return count;
}