class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if (target<n || target > n * k) {
            return 0;
        }
        const int MOD = 1000000007;
        vector<vector<int>> memo(n + 1, vector<int>(target - n + 1, -1));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i == 0) {
                return j == 0;
            }
            int& res = memo[i][j];
            if (res != -1) {
                return res;
            }
            res = 0;
            for (int x = 0; x < k && x <= j; x++) {
                res = (res + dfs(i - 1, j - x)) % MOD;
            }
            return res;
        };
        return dfs(n, target - n);
    }
};