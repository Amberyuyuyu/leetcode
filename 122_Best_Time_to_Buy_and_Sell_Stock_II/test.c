int maxProfit(int* prices, int pricesSize) {
    int ret = 0;
    for (int i = 1; i < pricesSize; i++) {
        ret += fmax(0, prices[i] - prices[i - 1]);
    }
    return ret;
}