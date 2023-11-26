class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        sort(ages.begin(), ages.end());
        int l = 0;
        int r = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (ages[i] < 15) {
                continue;
            }
            while (ages[l] <= 0.5 * ages[i] + 7) {
                l++;
            }
            while (r + 1 < n && ages[r + 1] <= ages[i]) {
                r++;
            }
            ans += r - l;
        }
        return ans;
    }
};