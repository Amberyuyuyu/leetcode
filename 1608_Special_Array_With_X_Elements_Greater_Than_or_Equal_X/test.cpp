class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int x = 1, n = nums.size(); x <= n; ++x) {
            if (x == n - (lower_bound(nums.begin(), nums.end(), x) - nums.begin())) {
                return x;
            }
        }
        return -1;
    }
};