class MyStack {
public:
    queue<int> Q1, Q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(Q1.empty()) {
            Q1.push(x);
            while(!Q2.empty()) {
                Q1.push(Q2.front());
                Q2.pop();
            }
        }
        else {
            Q2.push(x);
            while(!Q1.empty()) {
                Q2.push(Q1.front());
                Q1.pop();
            }
        }
    }
    
    int pop() {
        int top_element = top();
        if(Q1.empty()) Q2.pop();
        else Q1.pop();
        return top_element;
    }
    
    int top() {
        return Q1.empty() ? Q2.front() : Q1.front();
    }
    
    bool empty() {
        if(Q1.empty() && Q2.empty()) return true;
        return false;
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
