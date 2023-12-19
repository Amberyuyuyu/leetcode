class MinStack {
public:
    stack<int> vals;
    stack<int> minvals;

    MinStack() {

    }

    void push(int val) {
        vals.emplace(val);
        if (minvals.empty()) {
            minvals.emplace(val);
        }
        else {
            minvals.emplace(min(minvals.top(), val));
        }
    }

    void pop() {
        vals.pop();
        minvals.pop();
    }

    int top() {
        return vals.top();
    }

    int getMin() {
        return minvals.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */