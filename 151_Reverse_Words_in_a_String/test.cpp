class Solution {
public:
    string reverseWords(string s) {
        vector<string> a;
        if (s.size() <= 1) {
            return s;
        }
        stringstream ss(s);
        string x;
        while (ss >> x) {
            a.push_back(x);
        }
        s.clear();
        int i = a.size() - 1;
        while (i >= 0) {
            s += a[i];
            s += ' ';
            i--;
        }
        s.pop_back();
        return s;
    }
};