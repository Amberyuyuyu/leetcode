class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s.find(s[i]) != t.find(t[i])) {
                return false;
            }
        }
        // unordered_map<char,char> map_s;
        // unordered_map<char,char> map_t;
        // for(int i=0; i<s.size(); i++){
        //     char char_s = s[i];
        //     char char_t = t[i];
        //     if((map_s.count(char_s)&&map_s[char_s]!=char_t)
        //     || (map_t.count(char_t) && map_t[char_t]!=char_s)){
        //         return false;
        //     }
        //     map_s[char_s] = char_t;
        //     map_t[char_t] = char_s;
        // }
        return true;
    }
};