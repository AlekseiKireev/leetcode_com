class Solution {

public:
    int evalRPN(vector<string>& tokens) {
        
        const unordered_map<char, function<int (int,int)>> OperatorToLambda = { // const unordered_map<char, int(*) (int,int)> OperatorToLambda = { // good!
        {'+', [](const int f, const int s){return f+s;}},
        {'-', [](const int f, const int s){return f-s;}},
        {'*', [](const int f, const int s){return f*s;}},
        {'/', [](const int f, const int s){return f/s;}}
        };

        stack<int> Numbs;
        
        for(const string& token : tokens){

            if(token.size() == 1 && ispunct(token.front())){

                // обозначение операндов следует из примеров: ["2","1","/"] --> 2 / 1 -- то есть операнд, расположенный ближе к оператору -- стоит от него справа в выражении. В случае использовании стека элемент на вершине ближе всего к оператору
                const int  RightOperand = Numbs.top();  Numbs.pop();
                const int  LeftOperand = Numbs.top();  Numbs.pop();

                Numbs.push(OperatorToLambda.at(token.front())(LeftOperand, RightOperand));

            }else{
                Numbs.push(stoll(token));
            }
        }

        return Numbs.top();
    }
};
