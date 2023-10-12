class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, bool>map;
        for (int num : nums) {
            if (map[num]) {
                return num;
            }
            map[num] = true;
        }
        return -1;
    }
};