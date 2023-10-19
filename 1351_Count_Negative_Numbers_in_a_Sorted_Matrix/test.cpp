class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ret = 0;
        for (auto x : grid) {
            for (int t = 0; t < x.size(); t++) {
                if (x[t] < 0) {
                    ret += x.size() - t;
                    break;
                }
            }
        }
        return ret;
    }
};