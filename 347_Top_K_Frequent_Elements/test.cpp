class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        map<int, int> fir;
        for (auto& e : nums) {
            fir[e]++;
        }
        multimap<int, int, greater<int>>sec;
        for (auto& kv : fir) {
            sec.insert(make_pair(kv.second, kv.first));
        }
        auto it = sec.begin();
        while (it != sec.end()) {
            if (k == 0) {
                break;
            }
            ret.push_back(it->second);
            ++it;
            --k;
        }
        return ret;
    }
};