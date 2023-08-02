int flipgame(int* fronts, int frontsSize, int* backs, int backsSize) {
    int hash[2000] = { 0 };
    for (int i = 0; i < backsSize; i++) {
        if (fronts[i] == backs[i]) {
            hash[fronts[i]]++;
        }
    }
    int min = INT_MAX;
    for (int i = 0; i < frontsSize; i++) {
        if (hash[fronts[i]] == 0) {
            min = fmin(min, fronts[i]);
        }
        if (hash[backs[i]] == 0) {
            min = fmin(min, backs[i]);
        }
    }

    return min == INT_MAX ? 0 : min;
}