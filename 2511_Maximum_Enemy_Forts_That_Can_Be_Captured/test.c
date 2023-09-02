int captureForts(int* forts, int fortsSize) {
    int ret = 0;
    int pre = -1;
    for (int i = 0; i < fortsSize; i++) {
        if (forts[i] == 1 || forts[i] == -1) {
            if (pre >= 0 && forts[i] != forts[pre]) {
                ret = fmax(ret, i - pre - 1);
            }
            pre = i;
        }
    }
    return ret;
}