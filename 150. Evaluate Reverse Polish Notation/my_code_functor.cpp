class Solution {

/*
Compile Error

Line 4: Char 31: error: 'auto' not allowed in template argument
    4 | const unordered_map<  string, auto>  > OperatorToFuctor{
*/
// https://en.cppreference.com/w/cpp/utility/functional --> Operator function objects
const unordered_map<  string, function<int (int, int)>  > OperatorToFuctor{
    {"+", plus<int>()},
    {"-", minus<int>()},
    {"*", multiplies<int>()},
    {"/", divides<int>()}
};

public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int, vector<int>> Numbs;
        
        for(const string& token : tokens){
            
            if(OperatorToFuctor.count(token)){
                
                const int  RightOperand = Numbs.top();  Numbs.pop();
                const int  LeftOperand = Numbs.top();  Numbs.pop();
                Numbs.push(OperatorToFuctor.at(token)(LeftOperand, RightOperand));
                
            }else{
                
                Numbs.push(stoi(token));
                
            }
            
        }

        return Numbs.top();
    }
};
