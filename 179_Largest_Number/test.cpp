class Solution {
public:
    static bool cmp(string& left, string& right)
    {
        return left + right > right + left;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for (int i : nums) {
            str.push_back(to_string(i));
        }
        sort(str.begin(), str.end(), cmp);
        if (str[0] == "0") {
            return "0";
        }
        string res;
        for (int i = 0; i < str.size(); i++) {
            res += str[i];
        }
        return res;
    }
};