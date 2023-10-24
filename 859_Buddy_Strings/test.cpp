class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int cnt = 0;
        if (s.size() != goal.size()) {
            return false;
        }
        int diff1 = -1;
        int diff2 = -1;
        int chars[26];
        memset(chars, 0, sizeof(chars));
        bool valid_no_diff = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                cnt++;
                if (cnt > 2) {
                    return false;
                }
                if (cnt == 1) {
                    diff1 = i;
                }
                if (cnt == 2) {
                    diff2 = i;
                }
            }
            chars[s[i] - 'a']++;
            if (chars[s[i] - 'a'] >= 2) {
                valid_no_diff = true;
            }
        }
        if (cnt == 0 && valid_no_diff) {
            return true;
        }
        if (cnt == 2 && s[diff1] == goal[diff2] && s[diff2] == goal[diff1]) {
            return true;
        }
        return false;
    }
};