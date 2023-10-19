class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for (int i : arr) {
            if (st.count(i * 2) || (i % 2 == 0) && st.count(i / 2)) {
                return true;
            }
            st.insert(i);
        }
        return false;
    }
};