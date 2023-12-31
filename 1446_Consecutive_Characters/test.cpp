class Solution {
public:
    int maxPower(string s) {
        int chCount = 1, maxCount = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++chCount;
            }
            else {
                chCount = 1;
            }
            if (chCount > maxCount) {
                maxCount = chCount;
            }
        }
        return maxCount;
    }
};