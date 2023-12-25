class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxv = 0;
        for (auto x : nums) {
            maxv = max(maxv, x);
        }
        return k * (maxv + maxv + k - 1) / 2;
    }
};