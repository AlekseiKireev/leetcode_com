class Solution {

public:

  int evalRPN(const vector<string>& tokens) {

    stack<int, vector<int>> stack;
    
    for (const string& token : tokens) {
        
      if (token == "+") { 
       assert(stack.size() >= 2); 
       int second = stack.top(); 
       stack.pop();
       stack.top() += second;

      } 
      else if (token == "-") { 
       assert(stack.size() >= 2); 
       int second = stack.top(); 
       stack.pop();
       stack.top() -= second;

      } 
      else if (token == "*") { 
       assert(stack.size() >= 2); 
       int second = stack.top(); 
       stack.pop();
       stack.top() *= second;

      } 
      else if (token == "/") { 
       assert(stack.size() >= 2); 
       int second = stack.top(); 
       stack.pop();
       stack.top() /= second; 

      } else {

       stack. push(stoi(token));
      }
    }

    assert(stack.size() == 1); 
    return stack.top();
  }

};
