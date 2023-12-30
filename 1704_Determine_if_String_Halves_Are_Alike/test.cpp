class Solution {
public:
    int is_a_vowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ? 1 : 0);
    }
    bool halvesAreAlike(string s) {
        int left_cnt = 0, right_cnt = 0;
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            left_cnt += is_a_vowel(s[i]);
            right_cnt += is_a_vowel(s[j]);
        }
        return left_cnt == right_cnt;
    }
};