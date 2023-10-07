class Solution {
public:
    int work(vector<int>& nums, int k) {
        int len = 0;
        for (int num : nums) {
            if (len < k || nums[len - k] != num) {
                nums[len++] = num;
            }
        }
        return len;
    }
    int removeDuplicates(vector<int>& nums) {
        return work(nums, 2);
    }
};