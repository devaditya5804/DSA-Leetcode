class MinStack {
    // derivation
    // val < mini
    // val - mini < 0
    // 2 * val - mini < val
    // new_val < val 
    // thus new_val is always less than val
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        mini = 1e9;
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        }
        else {
            if (val > mini) st.push(val);
            else {
                // val <= mini
                long long new_val = 2LL * val - mini;
                st.push(new_val);
                mini = val;
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        if (st.top() < mini) {
            mini = 2 * mini - st.top();
            st.pop();
        }
        else {
            st.pop();
        }
    }
    
    int top() {
        if (st.top() < mini) return mini;
        return st.top();
    }
    
    int getMin() {
        return mini;
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