
int cmp(void* p, void* q) {
    return *(int*)q - *(int*)p;
}
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int ret = 0;
    int i = 0;
    int j = 0;
    while (i < gSize && j < sSize) {
        if (g[i] <= s[j]) {
            i++;
            j++;
            ret++;
        }
        else {
            i++;
        }
    }
    return ret;
}