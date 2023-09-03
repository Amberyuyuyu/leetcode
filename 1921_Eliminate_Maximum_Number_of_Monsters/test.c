int cmp(void* p, void* q) {
    return *(int*)p - *(int*)q;
}
int eliminateMaximum(int* dist, int distSize, int* speed, int speedSize) {
    int time_arr[distSize];

    for (int i = 0; i < distSize; i++) {
        time_arr[i] = dist[i] / speed[i];
        if (dist[i] % speed[i] != 0) {
            time_arr[i] += 1;
        }
    }
    qsort(time_arr, distSize, sizeof(int), cmp);
    for (int i = 0; i < distSize; i++) {
        if (time_arr[i] <= i) {
            return i;
        }
    }
    return distSize;
}