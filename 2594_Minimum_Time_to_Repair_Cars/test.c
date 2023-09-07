int find_min(int* ranks, int ranksSize) {
    int min = ranks[0];
    for (int i = 1; i < ranksSize; i++) {
        min = fmin(min, ranks[i]);
    }
    return min;
}
long long cal_sum(int* ranks, long long t, int ranksSize) {
    long long sum = 0;
    for (int i = 0; i < ranksSize; i++) {
        sum += sqrt(t / ranks[i]);
    }
    return sum;
}
long long repairCars(int* ranks, int ranksSize, int cars) {
    long long left = find_min(ranks, ranksSize);
    long long right = left * cars * cars;
    long long mid = 0;

    while (left <= right) {
        long long sum = 0;
        mid = left + (right - left) / 2;
        sum = cal_sum(ranks, mid, ranksSize);
        if (sum >= cars) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return right + 1;
}