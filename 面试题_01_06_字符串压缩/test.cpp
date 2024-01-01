class Solution {
public:
    string compressString(string S) {
        string ret;
        int count = 1;
        for (int i = 0; i < S.size(); ++i) {
            if (i + 1 < S.size() && S[i] == S[i + 1]) {
                count++;
                continue;
            }
            ret.push_back(S[i]);
            ret.append(to_string(count));
            count = 1;
        }
        return ret.size() >= S.size() ? S : ret;
    }
};