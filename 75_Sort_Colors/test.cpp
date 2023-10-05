class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) {
            return;
        }
        int zero = 0;
        int one = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                zero++;
            }
            else if (nums[i] == 1) {
                one++;
            }
        }
        for (int i = 0; i < zero; i++) {
            nums[i] = 0;
        }
        for (int i = zero; i < one + zero; i++) {
            nums[i] = 1;
        }
        for (int i = one + zero; i < size; i++) {
            nums[i] = 2;
        }
    }
};