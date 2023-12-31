class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int pos = 0;
        while (start < s.length()) {
            pos = s.find(' ', start);
            if (pos == -1) {
                pos = s.size();
            }
            std::reverse(s.begin() + start, s.begin() + pos);
            start = pos + 1;
        }
        return s;
    }
};