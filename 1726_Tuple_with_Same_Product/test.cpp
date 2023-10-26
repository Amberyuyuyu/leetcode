class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mulCount;
        int n = nums.size();
        int mul;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mul = nums[i] * nums[j];
                mulCount[mul]++;
            }
        }
        int ans = 0;
        for (auto& [_, v] : mulCount) {
            ans += v * (v - 1) / 2;
        }
        return ans << 3;
    }
};