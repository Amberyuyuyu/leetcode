class MyCalendar {
public:
    map<int, int> c;
    MyCalendar() {

    }

    bool book(int start, int end) {
        auto t = c.upper_bound(start);
        if (t->second >= end || t == c.end()) {
            c.insert(make_pair(end, start));
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */