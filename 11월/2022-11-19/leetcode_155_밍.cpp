class MinStack {
public:
    stack<int> s;
    multiset<int> ms;
    
    MinStack() {
        while (!s.empty()) s.pop();
    }
    
    void push(int val) {
        s.push(val);
        ms.insert(val);
    }
    
    void pop() {
        multiset<int>::iterator it = ms.find(s.top());
        ms.erase(it);
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return *ms.begin();
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