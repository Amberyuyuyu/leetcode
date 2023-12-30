class Solution {
public:
    static bool compareStrings(const string& str1, const string& str2) {
        return str1 < str2;
    }
    vector<int> lexicalOrder(int n) {
        vector<string> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = to_string(i + 1);
        }
        sort(arr.begin(), arr.end());
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = stoi(arr[i]);
        }
        return res;
    }
};