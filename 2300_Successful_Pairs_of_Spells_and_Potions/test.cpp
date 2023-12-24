class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> ans(n);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; ++i) {
            ans[i] = potions.end() - lower_bound(potions.begin(), potions.end(), success * 1.0 / spells[i]);
        }
        return ans;
    }
};