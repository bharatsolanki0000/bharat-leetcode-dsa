class MinStack {
    stack<int> st, mini;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        
        if(mini.empty() || mini.top()>=value){
            mini.push(value);
        }

        st.push(value);
    }
    
    void pop() {
        
        int topper=st.top();
        st.pop();

        if(mini.top()==topper){
            mini.pop();
        }

    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */