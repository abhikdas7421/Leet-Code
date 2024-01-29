class MyQueue {
    stack<int> st;
public:
    MyQueue() {
        
    }
    
    void solve(stack<int> &st, int x) {
        if(st.empty()) {
            st.push(x);
            return;
        }
        
        int temp = st.top(); st.pop();
        solve(st, x);
        st.push(temp);
    }
    
    void push(int x) {
        solve(st, x);
    }
    
    int pop() {
        int popedElement = st.top(); st.pop();
        return popedElement;
    }
    
    int peek() {
        int peekElement = st.top();
        return peekElement;
    }
    
    bool empty() {
        return st.empty();
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