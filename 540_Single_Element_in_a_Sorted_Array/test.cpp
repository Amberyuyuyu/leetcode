class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ret = 0;
        for (int num : nums) {
            ret ^= num;
        }
        return ret;
    }
};