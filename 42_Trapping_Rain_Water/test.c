int trap(int* height, int heightSize) {
    int ret = 0;
    int pre_max[heightSize];
    int suf_max[heightSize];
    pre_max[0] = height[0];
    for (int i = 1; i < heightSize; i++) {
        pre_max[i] = fmax(pre_max[i - 1], height[i]);
    }
    suf_max[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; i--) {
        suf_max[i] = fmax(suf_max[i + 1], height[i]);
    }
    for (int i = 0; i < heightSize; i++) {
        ret += fmin(pre_max[i], suf_max[i]) - height[i];
    }
    return ret;
}