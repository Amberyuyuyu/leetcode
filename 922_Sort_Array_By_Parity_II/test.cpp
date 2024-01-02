class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1;
        int n = nums.size();
        while (i < n && j < n) {
            while (i < n && 0 == (nums[i] & 1)) {
                i += 2;
            }
            while (j < n && 0 != (nums[j] & 1)) {
                j += 2;
            }
            if (i >= n || j >= n) {
                break;
            }
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};