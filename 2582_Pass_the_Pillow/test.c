int passThePillow(int n, int time) {
    int ret = time % (2 * (n - 1));
    return ret < n ? ret + 1 : n * 2 - ret - 1;
}