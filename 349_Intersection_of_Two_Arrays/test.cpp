class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        for (auto e : nums1) {
            s1.insert(e);
        }
        unordered_set<int> s2;
        for (auto e : nums2) {
            s2.insert(e);
        }
        vector<int> vRet;
        for (auto e : s1) {
            if (s2.find(e) != s2.end()) {
                vRet.push_back(e);
            }
        }
        return vRet;
    }
};