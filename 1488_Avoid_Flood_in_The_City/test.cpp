class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int>lastRainDay;
        set<int> sunnyDays;
        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
            if (lake > 0) {
                if (lastRainDay.count(lake)) {
                    auto it = sunnyDays.upper_bound(lastRainDay[lake]);
                    if (it == sunnyDays.end()) return {};
                    ans[*it] = lake;
                    sunnyDays.erase(it);
                }
                lastRainDay[lake] = i;
            }
            else {
                sunnyDays.insert(i);
                ans[i] = 1;
            }
        }
        return ans;
    }
};