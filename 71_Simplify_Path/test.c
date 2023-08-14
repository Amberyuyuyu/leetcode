char* simplifyPath(char* path) {
    int n = strlen(path);
    char* stack[n];
    int size = 0;
    for (char* s = strtok(path, "/"); s; s = strtok(NULL, "/")) {
        if (strcmp(s, ".") == 0) {

        }
        else if (strcmp(s, "..") == 0) {
            size = fmax(0, size - 1);
        }
        else {
            stack[size++] = s;
        }
    }
    if (size == 0) return "/";
    char* res = calloc(n + 1, sizeof(char));
    for (int i = 0; i < size; i++) {
        strcat(res, "/");
        strcat(res, stack[i]);
    }
    return res;
}