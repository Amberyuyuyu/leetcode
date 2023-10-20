class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        s += ' ';
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ' ' && s[i - 1] != ' ') {
                ans++;
            }
        }
        return ans;
    }
};