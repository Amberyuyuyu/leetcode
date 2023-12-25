class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        int mx[82]{};
        for (int num : nums) {
            int s = 0;
            for (int x = num; x; x /= 10) {
                s += x % 10;
            }
            if (mx[s]) {
                ans = max(ans, mx[s] + num);
            }
            mx[s] = max(mx[s], num);
        }
        return ans;
    }
};