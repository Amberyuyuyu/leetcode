class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int m = n - k;
        int s = accumulate(cardPoints.begin(), cardPoints.begin() + m, 0);
        int min_s = s;
        for (int i = m; i < n; ++i) {
            s += cardPoints[i] - cardPoints[i - m];
            min_s = min(min_s, s);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - min_s;
    }
};