class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        if (len1 != len2) {
            return false;
        }
        int s_mask = 0, t_mask = 0;
        vector<int> s_cnt(26), t_cnt(26);
        for (char c : word1) {
            s_mask |= 1 << (c - 'a');
            s_cnt[c - 'a']++;
        }
        for (char c : word2) {
            t_mask |= 1 << (c - 'a');
            t_cnt[c - 'a']++;
        }
        sort(s_cnt.begin(), s_cnt.end());
        sort(t_cnt.begin(), t_cnt.end());
        return s_mask == t_mask && s_cnt == t_cnt;
    }
};