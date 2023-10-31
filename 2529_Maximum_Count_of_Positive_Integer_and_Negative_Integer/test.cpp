class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int num : nums) {
            if (num < 0) {
                cnt++;
            }
            if (num == 0) {
                n--;
            }
        }
        return max(cnt, n - cnt);
    }
};