class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for (int num : nums) {
            xorsum ^= num;
        }
        int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));

        int a = 0;
        int b = 0;
        for (int num : nums) {
            if (num & lsb) {
                a ^= num;
            }
            else {
                b ^= num;
            }
        }
        return { a,b };
    }
};