

int minCount(int* coins, int coinsSize) {
    int ret = 0;
    for (int i = 0; i < coinsSize; i++) {
        ret += coins[i] / 2;
        ret += coins[i] % 2;
    }
    return ret;
}
