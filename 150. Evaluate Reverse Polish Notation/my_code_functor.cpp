/*
Time complexity: O(tokens.size())
Space complexity: O(1)
*/    
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

                // если перепутать порядок аргументов: Numbs.push(OperatorToFuctor.at(token)(RightOperand, LeftOperand)); 
                // будет ошибка: Wrong Answer 2 / 21 Input tokens = ["4","13","5","/","+"] Use Testcase Output 4 Expected 6
                Numbs.push(OperatorToFuctor.at(token)(LeftOperand, RightOperand)); 
                
            }else{
                
                Numbs.push(stoi(token));
                
            }
            
        }

        return Numbs.top();
    }
};
