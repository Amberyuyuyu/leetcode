class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        while (k--) {
            int x = pq.top();
            pq.pop();
            pq.emplace(int(sqrt(x)));
        }
        long long res = 0;
        while (pq.size()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};