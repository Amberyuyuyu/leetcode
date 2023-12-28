class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> left(26), in_ans(26);
        for (char c : s) {
            left[c - 'a']++;
        }
        string ans;
        for (char c : s) {
            left[c - 'a']--;
            if (in_ans[c - 'a']) {
                continue;
            }
            while (!ans.empty() && c < ans.back() && left[ans.back() - 'a']) {
                in_ans[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans += c;
            in_ans[c - 'a'] = true;
        }
        return ans;
    }
};