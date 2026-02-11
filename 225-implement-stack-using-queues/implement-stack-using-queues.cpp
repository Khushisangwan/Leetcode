class MyStack {
public:
    queue<int>que;
    void push(int x) {
        que.push(x);
        for(int i=0;i<que.size()-1;i++){
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int val = que.front();
        que.pop();
        return val;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
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