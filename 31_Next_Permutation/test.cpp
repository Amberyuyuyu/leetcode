class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cur = nums.size() - 2;
        while (cur >= 0 && nums[cur] >= nums[cur + 1]) {
            cur--;
        }
        if (cur < 0) {
            sort(nums.begin(), nums.end());
        }
        else {
            int pos = nums.size() - 1;
            while (nums[pos] <= nums[cur]) {
                pos--;
            }
            swap(nums[cur], nums[pos]);
            reverse(nums.begin() + cur + 1, nums.end());
        }
    }
};