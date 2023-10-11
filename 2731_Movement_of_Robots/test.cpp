class Solution {
    const int mod = 1e9 + 7;
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] += s[i] == 'R' ? d : -d;
        }
        sort(nums.begin(), nums.end());
        long long sum = 0LL;
        long long res = 0LL;
        for (int i = 1; i < n; i++) {
            long long dis = (long long)nums[i] - nums[i - 1];
            sum = sum % mod + (i * dis) % mod;
            res = res % mod + sum % mod;
        }
        return res % mod;
    }
};