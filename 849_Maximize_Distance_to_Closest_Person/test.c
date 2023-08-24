int maxDistToClosest(int* seats, int seatsSize) {
    int ret = 0;
    int left = 0;
    while (left < seatsSize && seats[left] == 0) {
        left++;
    }
    ret = fmax(ret, left);
    while (left < seatsSize) {
        int right = left + 1;
        while (right < seatsSize && seats[right] == 0) {
            right++;
        }
        if (right == seatsSize) {
            ret = fmax(ret, right - left - 1);
        }
        else {
            ret = fmax(ret, (right - left) / 2);
        }
        left = right;
    }
    return ret;
}