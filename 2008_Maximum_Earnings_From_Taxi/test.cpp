class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pair<int, int>>> groups(n + 1);
        for (auto& r : rides) {
            int start = r[0], end = r[1], tip = r[2];
            groups[end].emplace_back(start, end - start + tip);
        }
        vector<long long> memo(n + 1, -1);
        function<long long(int)> dfs = [&](int i) ->long long {
            if (i == 1) {
                return 0;
            }
            auto& res = memo[i];
            if (res != -1) {
                return res;
            }
            res = dfs(i - 1);
            for (auto& [s, t] : groups[i]) {
                res = max(res, dfs(s) + t);
            }
            return res;
        };
        return dfs(n);
    }
};