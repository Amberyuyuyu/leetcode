class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int hash[26] = { 0 };
        for (int i = 0; i < word1.length(); ++i) {
            hash[word1[i] - 'a']++;
            hash[word2[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (abs(hash[i]) > 3) {
                return false;
            }
        }
        return true;
    }
};