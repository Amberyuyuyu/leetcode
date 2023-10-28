class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> m;
        sort(nums.begin(), nums.end());
        vector<int> dp = { 0,nums[0] };
        m[nums[0]] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            ++m[nums[i]];
            if (nums[i] != dp.back()) {
                dp.push_back(nums[i]);
            }
        }
        int last = dp[1];
        dp[1] = dp[1] * m[dp[1]];
        for (int i = 2; i < dp.size(); ++i) {
            if (dp[i] - last == 1) {
                last = dp[i];
                dp[i] = max(dp[i - 1], dp[i - 2] + dp[i] * m[dp[i]]);
            }
            else {
                last = dp[i];
                dp[i] = dp[i - 1] + dp[i] * m[dp[i]];
            }
        }
        return dp[dp.size() - 1];
    }
};