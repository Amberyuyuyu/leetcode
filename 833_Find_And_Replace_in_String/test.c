struct map {
    int index;
    char* source;
    char* target;
};
int cmp(void* p, void* q) {
    return (*(struct map*)q).index - (*(struct map*)p).index;
}
char* findReplaceString(char* s, int* indices, int indicesSize, char** sources, int sourcesSize, char** targets, int targetsSize) {
    struct map* arr = (struct map*)calloc(indicesSize, sizeof(struct map));
    char* res = (char*)calloc(50000, sizeof(char));
    char* buf = (char*)calloc(50000, sizeof(char));
    strcpy(res, s);
    for (int i = 0; i < indicesSize; i++) {
        arr[i].index = indices[i];
        arr[i].source = sources[i];
        arr[i].target = targets[i];
    }
    qsort(arr, indicesSize, sizeof(struct map), cmp);
    for (int i = 0; i < indicesSize; i++) {
        if (strncmp(&res[arr[i].index], arr[i].source, strlen(arr[i].source)) == 0) {
            memset(buf, 0, sizeof(char));
            strcpy(buf, arr[i].target);
            strcat(buf, &res[arr[i].index + strlen(arr[i].source)]);
            memset(&res[arr[i].index], 0, sizeof(char));
            strcat(&res[arr[i].index], buf);
        }
    }
    return res;
}