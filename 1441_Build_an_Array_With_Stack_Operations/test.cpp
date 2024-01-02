class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;
        int index = 0;
        int data = 1;
        while (index < target.size()) {
            ret.push_back("Push");
            if (data != target[index]) {
                ret.push_back("Pop");
            }
            else {
                index++;
            }
            ++data;
        }
        return ret;
    }
};