class MyStack {
    queue<int>first;
    queue<int>second;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        
        first.push(x);
    }

    int popAndTop(bool isPop){

        int size=first.size();
        while(size>1){
            second.push(first.front());
            first.pop();
            size--;
        }

        int ans=first.front();

        if(isPop){
            first.pop();
        }
        else{
            second.push(first.front());
            first.pop();
        }
        

        size=second.size();
        while(size--){
            first.push(second.front());
            second.pop();
        }

        return ans;
    }
    
    int pop() {
        return popAndTop(true);
       
    }
    
    int top() {
        return popAndTop(false);
    }
    
    bool empty() {
        
        return first.empty();
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