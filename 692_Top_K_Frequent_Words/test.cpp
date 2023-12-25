class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> countMap;
        for (auto e : words) {
            countMap[e]++;
        }
        multimap<int, string, greater<int>> sortMap;
        for (auto kv : countMap) {
            sortMap.insert(make_pair(kv.second, kv.first));
        }
        vector<string> v;
        auto it = sortMap.begin();
        while (it != sortMap.end()) {
            if (k == 0) {
                break;
            }
            v.push_back(it->second);
            ++it;
            --k;
        }
        return v;
    }
};