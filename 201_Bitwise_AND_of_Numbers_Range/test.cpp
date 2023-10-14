class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int mask = 1 << 30;
        int ans = 0;
        while (mask > 0 && (left & mask) == (right & mask)) {
            ans |= left & mask;
            mask >>= 1;
        }
        return ans;
    }
};