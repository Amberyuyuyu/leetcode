class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 1 && target == nums[0]) {
            return true;
        }
        if (len == 1 && target != nums[0]) {
            return false;
        }
        int flag = 0;
        for (int num : nums) {
            if (num != nums[0]) {
                flag = 1;
            }
        }
        if (flag == 0) {
            if (target == nums[0]) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (nums[len - 1] > nums[0]) {
            if (target > nums[len - 1] || target < nums[0]) {
                return false;
            }
            else {
                int left = 0;
                int right = len - 1;
                return myFind(nums, target, left, right);
            }
        }
        else if (nums[len - 1] <= nums[0]) {
            int k;
            for (int i = 1; i < len; i++) {
                if (nums[i] < nums[i - 1]) {
                    k = i;
                    break;
                }
            }
            if (target > nums[0]) {
                int left = 0;
                int right = k - 1;
                return myFind(nums, target, left, right);
            }
            else if (target < nums[len - 1]) {
                int left = k;
                int right = len - 1;
                return myFind(nums, target, left, right);
            }
            else if (target == nums[0] || target == nums[len - 1]) {
                return true;
            }
            else {
                return false;
            }
        }
        return false;
    }
private:
    bool myFind(vector<int>& nums, int target, int left, int right) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                return true;
            }
        }
        if (nums[left] == target || nums[right] == target) {
            return true;
        }
        return false;
    }
};