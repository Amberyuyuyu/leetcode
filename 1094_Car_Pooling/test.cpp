class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int d[1001]{};
        for (auto& t : trips) {
            int num = t[0], from = t[1], to = t[2];
            d[from] += num;
            d[to] -= num;
        }
        int s = 0;
        for (int v : d) {
            s += v;
            if (s > capacity) {
                return false;
            }
        }
        return true;
    }
};