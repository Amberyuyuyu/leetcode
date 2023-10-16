class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        int small = INT_MAX;
        int mid = INT_MAX;
        for (int num : nums) {
            if (num <= small) {
                small = num;
            }
            else if (num <= mid) {
                mid = num;
            }
            else if (num > mid) {
                return true;
            }
        }
        return false;
    }
};