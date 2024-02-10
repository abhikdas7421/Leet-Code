class MyStack {
    queue<int> q1;
    // queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        /*q2.push(x);
        
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        swap(q1,q2);*/
        
        // Follow-up:- implement using only one queue
        
        q1.push(x);
        int size = q1.size()-1;
        
        while(size--) {
            int temp = q1.front();
            q1.pop();
            q1.push(temp);
        }
    }
    
    int pop() {
        int popedElement = q1.front();
        q1.pop();
        
        return popedElement;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */