

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char* s, int* returnSize) {
    int hash_map[26];
    int len = strlen(s);
    *returnSize = 0;
    int* ret = (int*)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        hash_map[s[i] - 'a'] = i;
    }
    int end = 0;
    int start = 0;
    for (int i = 0; i < len; i++) {
        end = fmax(end, hash_map[s[i] - 'a']);
        if (i == end) {
            ret[(*returnSize)++] = end - start + 1;
            start = end + 1;
        }
    }
    return ret;
}