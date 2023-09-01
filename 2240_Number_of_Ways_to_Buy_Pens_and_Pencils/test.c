

long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    long long ret = 0;
    for (int i = 0; i <= total / cost1; i++) {
        ret += (total - cost1 * i) / cost2 + 1;
    }
    return ret;
}