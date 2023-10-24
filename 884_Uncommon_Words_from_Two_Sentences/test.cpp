class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        vector<string> res;
        stringstream a, b;
        string s;
        a << s1;
        b << s2;
        while (a >> s) {
            mp[s]++;
        }
        while (b >> s) {
            mp[s]++;
        }
        for (auto m : mp) {
            if (m.second == 1) {
                res.push_back(m.first);
            }
        }
        return res;
    }
};