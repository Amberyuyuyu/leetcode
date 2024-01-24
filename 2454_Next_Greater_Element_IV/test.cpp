class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1), s, t;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            while (!t.empty() && nums[t.back()] < x) {
                ans[t.back()] = x;
                t.pop_back();
            }
            int j = s.size();
            while (j && nums[s[j - 1]] < x) {
                j--;
            }
            t.insert(t.end(), s.begin() + j, s.end());
            s.resize(j);
            s.push_back(i);
        }
        return ans;
    }
};