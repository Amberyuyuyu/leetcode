class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) {
            return true;
        }
        for (int i = 0, j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) {
                if (++i == s.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};