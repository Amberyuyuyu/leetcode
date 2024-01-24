class CountIntervals {
    map<int, int> m;
    int cnt = 0;

public:
    CountIntervals() {}

    void add(int left, int right) {
        for (auto it = m.lower_bound(left); it != m.end() && it->second <= right; m.erase(it++)) {
            int l = it->second, r = it->first;
            left = min(left, l);
            right = max(right, r);
            cnt -= r - l + 1;
        }
        cnt += right - left + 1;
        m[right] = left;
    }

    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */