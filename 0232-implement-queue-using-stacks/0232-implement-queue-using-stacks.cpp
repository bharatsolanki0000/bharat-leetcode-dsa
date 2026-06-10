class MyQueue {
        stack<int> first;
        stack<int> second;
public:
    MyQueue() {
    }
    
    void push(int x) {
        
        int size=first.size();
        while(size--){
            second.push(first.top());
            first.pop();
        }

        second.push(x);

        while(!second.empty()){
            first.push(second.top());
            second.pop();
        }
    }
    
    int pop() {

      int ans=first.top();
      first.pop();
      return ans;
        
    }
    
    int peek() {

       return first.top();

    }
    
    bool empty() {

        return first.empty();
        
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