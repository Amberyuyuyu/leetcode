

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* p1, const void* p2) {
    int* r1 = *(int**)p1;
    int* r2 = *(int**)p2;
    return r1[1] != r2[1] ? r2[1] - r1[1] : r2[0] - r1[0];
}
int* filterRestaurants(int** restaurants, int restaurantsSize, int* restaurantsColSize, int veganFriendly, int maxPrice, int maxDistance, int* returnSize) {
    int** filtered = (int**)malloc(sizeof(int*) * restaurantsSize);
    int filteredSize = 0;
    for (int i = 0; i < restaurantsSize; i++) {
        if (restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
            if (veganFriendly && restaurants[i][2]) {
                filtered[filteredSize++] = restaurants[i];
            }
            if (!veganFriendly) {
                filtered[filteredSize++] = restaurants[i];
            }
        }
    }
    qsort(filtered, filteredSize, sizeof(int*), cmp);
    int* ret = (int*)malloc(sizeof(int) * filteredSize);
    for (int i = 0; i < filteredSize; i++) {
        ret[i] = filtered[i][0];
    }
    free(filtered);
    *returnSize = filteredSize;
    return ret;
}