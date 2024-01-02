class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ret(m, vector<int>(n, 0));
        int sz = original.size();
        if (sz != m * n) {
            return vector<vector<int>>();
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ret[i][j] = original[i * n + j];
            }
        }
        return ret;
    }
};