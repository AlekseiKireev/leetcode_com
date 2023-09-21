class MyQueue {

private:

stack<int, vector<int>> Input;
stack<int, vector<int>> Output;

void MakeOutput(){
    if(Output.empty()){
        while(!Input.empty()){
            Output.push(Input.top());
            Input.pop();
        }
    }
}

public:
    
    void push(int x) {
        Input.push(x);
    }
    
    int pop() {

        if(empty()){throw"";}
        MakeOutput();
        const int X = Output.top();
        Output.pop();
        return X;

    }
    
    int peek() {

        if(empty()){throw"";}
        MakeOutput();
        return Output.top();
    }
    
    bool empty() {
        return Input.empty() && Output.empty();
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
