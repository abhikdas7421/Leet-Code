class MyQueue {
    stack<int> input;
    stack<int> output;
public:
    MyQueue() {
        
    }
    
    void push(int x) { // T.C -> O(1)
        input.push(x);
    }
    
    int pop() { // T.C -> Amortised O(1)
        if(!output.empty()) {
            int poped = output.top();
            output.pop();
            return poped;
        }
        
        while(!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        
        int poped = output.top();
        output.pop();
        return poped;
    }
    
    int peek() { // T.C -> Amortised O(1)
        if(!output.empty()) {
            return output.top();
        }
        
        while(!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        
        int front = output.top();
        return front;
    }
    
    bool empty() { // T.C -> O(1)
        return input.empty() && output.empty();
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