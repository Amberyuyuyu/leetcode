class Solution {
public:
    int getSum(int a, int b) {
        if (!a) {
            return b;
        }
        if (!b) {
            return a;
        }
        int sum = a ^ b, carry = (unsigned int)(a & b) << 1;
        return getSum(carry, sum);
    }
};