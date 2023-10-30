class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        long long sum = 0, sum1 = 0;
        for (auto& i : nums) {
            sum += i;
            while (i) {
                sum1 += i % 10;
                i /= 10;
            }
        }
        return abs(sum - sum1);
    }
};