class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long result = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            result = (result + (long long)arr[i] * (i - left[i]) * (right[i] - i)) % mod;
        }
        return result;
    }
};