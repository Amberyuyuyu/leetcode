class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int res = 0;
        vector<vector<int>> a(n, vector<int>(26));
        for (int i = 0; i < n; ++i) {
            int len = words[i].size();
            for (int j = 0; j < len; ++j) {
                a[i][words[i][j] - 'a'] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int k = 0;
                int len = 0;
                while (k < 26) {
                    if (a[i][k] == 1 && a[j][k] == 1) {
                        len = 0;
                        break;
                    }
                    if (k == 25) {
                        len = words[i].size() * words[j].size();
                    }
                    k++;
                }
                res = max(res, len);
            }
        }
        return res;
    }
};