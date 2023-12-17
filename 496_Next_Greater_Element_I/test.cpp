class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next;
        stack<int> st;

        for (auto n : nums2) {
            if (!(st.empty() || st.top() > n)) {
                while (!st.empty() && st.top() < n) {
                    next[st.top()] = n;
                    st.pop();
                }
            }
            st.push(n);
        }
        vector<int> ans = vector<int>(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); ++i) {
            int n = nums1[i];
            if (next.count(n)) {
                ans[i] = next[n];
            }
        }
        return ans;
    }
};