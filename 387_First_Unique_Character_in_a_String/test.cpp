class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, bool> dic;
        for (char c : s) {
            dic[c] = dic.find(c) == dic.end();
        }
        for (int i = 0; i < s.size(); i++) {
            if (dic[s[i]]) {
                return i;
            }
        }
        return -1;
    }
};