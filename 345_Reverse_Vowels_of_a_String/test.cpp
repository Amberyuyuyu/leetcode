class Solution {
public:
    string reverseVowels(string s) {
        set<char> st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0; int j = s.size() - 1;
        while (i < j) {
            while (i < s.size() && !st.count(s[i])) {
                i++;
            }
            while (j > 0 && !st.count(s[j])) {
                j--;
            }
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};