class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        int maxNum = nums[0];
        int minNum = nums[0];
        int p = nums[0];
        for (int i = 1; i < n; ++i) {
            int m = maxNum;
            maxNum = max(max(maxNum * nums[i], nums[i]), minNum * nums[i]);
            minNum = min(min(m * nums[i], nums[i]), minNum * nums[i]);
            p = max(maxNum, p);
        }
        return p;
    }
};