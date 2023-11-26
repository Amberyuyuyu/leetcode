
class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        int mod = (int)1e9 + 7;
        int i = 0;
        long ans = 0;
        int j = drinks.size() - 1;
        while (i < staple.size() && j >= 0) {
            int sum = staple[i] + drinks[j];
            if (sum <= x) {
                i++;
                ans += j + 1;
                ans %= mod;
            }
            else {
                j--;
            }
        }
        return ans % mod;
    }
};