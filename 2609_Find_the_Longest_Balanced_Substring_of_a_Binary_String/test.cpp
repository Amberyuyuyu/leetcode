class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size(), idx = 0, ans = 0;
        while (idx < n) {
            int a = 0, b = 0;
            while (idx < n && s[idx] == '0' && ++a >= 0) {
                idx++;
            }
            while (idx < n && s[idx] == '1' && ++b >= 0) {
                idx++;
            }
            ans = max(ans, min(a, b) * 2);
        }
        return ans;
    }
};