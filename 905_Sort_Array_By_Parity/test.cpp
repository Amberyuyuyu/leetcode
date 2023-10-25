class Solution {
public:

    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (nums[i] % 2 == 0) {
                i++;
            }
            if (nums[j] % 2) {
                j--;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};