class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for (auto p : details) {
            int age = stoi(p.substr(11, 2));
            res += age > 60;
        }
        return res;
    }
};