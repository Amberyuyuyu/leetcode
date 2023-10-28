class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int f = 0;
        int s = 0;
        for (int x : satisfaction) {
            s += x;
            if (s <= 0) {
                break;
            }
            f += s;
        }
        return f;
    }
};