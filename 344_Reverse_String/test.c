void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    while (left < right) {
        s[left] ^= s[right];
        s[right] ^= s[left];
        s[left++] ^= s[right--];
    }
    return s;
}