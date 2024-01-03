class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int j = 0; j < n; ++j) {
            int i = lower_bound(nums.begin(), nums.begin() + j, target - nums[j]) - nums.begin();
            count += i;
        }
        return count;
    }
};