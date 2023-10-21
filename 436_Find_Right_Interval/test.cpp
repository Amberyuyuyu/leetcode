class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        vector<int> result;
        map<int, int> map;
        int index = 0;
        for (auto v : intervals) {
            map[v[0]] = index++;
        }
        for (auto v : intervals) {
            auto it = map.lower_bound(v[1]);
            if (it == map.end()) {
                result.emplace_back(-1);
            }
            else {
                result.emplace_back((*it).second);
            }
        }
        return result;
    }
};