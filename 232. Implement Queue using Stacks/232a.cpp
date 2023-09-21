class MyQueue {

private:

stack<int, vector<int>> in;
stack<int, vector<int>> out;

void PrepareOut(){
    if(out.empty()){
        while(! in.empty()){
            out.push(in.top());
            in.pop();
        }
    }
}

public:
    
    // MyQueue() {} // в нем нет необходимости
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(empty()){throw logic_error("pop from emty Queue");}
        PrepareOut();
        int x = out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        if(empty()){throw logic_error("peek from emty Queue");}
        PrepareOut();
        return out.top();
    }
    
    bool empty() {
        return (out.empty() && in.empty());
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
