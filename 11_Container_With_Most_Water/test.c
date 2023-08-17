int maxArea(int* height, int heightSize) {
    int ret = 0;
    int left = 0;
    int right = heightSize - 1;
    int area = 0;
    while (left < right) {
        area = (right - left) * fmin(height[left], height[right]);
        ret = fmax(ret, area);
        if (height[left] < height[right]) {
            left++;
        }
        else {
            right--;
        }
    }
    return ret;
}