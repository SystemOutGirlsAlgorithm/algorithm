class MyQueue {
public:
    stack<int> stk1, stk2;
    MyQueue() {
        while (!stk1.empty()) stk1.pop();
        while (!stk2.empty()) stk2.pop();
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int ret = stk2.top();
        stk2.pop();
        return ret;
    }
    
    int peek() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        return stk2.top();
    }
    
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */