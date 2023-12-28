class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        int n = pattern.size();
        int m = s.size();
        int wordStart = 0;
        int wordEnd = 0;
        char ch;
        string word;
        for (int i = 0; i < n; i++) {
            if (wordStart >= m) {
                return false;
            }
            while (wordEnd < m && s[wordEnd] != ' ') {
                wordEnd++;
            }
            word = s.substr(wordStart, wordEnd - wordStart);
            ch = pattern[i];
            if ((p2s.count(ch) && p2s[ch] != word) || (s2p.count(word) && s2p[word] != ch)) {
                return false;
            }
            p2s[ch] = word;
            s2p[word] = ch;
            wordStart = wordEnd + 1;
            wordEnd = wordStart;
        }

        return wordStart == m + 1;
    }
};