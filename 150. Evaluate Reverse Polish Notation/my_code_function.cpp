class Solution {

public:
    int evalRPN(vector<string>& tokens) {

        // https://en.cppreference.com/w/cpp/utility/functional/function
        const unordered_map<char, function<int (int,int)>> OperatorToLambda = { // const unordered_map<char, int(*) (int,int)> OperatorToLambda = { // good!
        // https://en.cppreference.com/w/cpp/language/lambda
            /*This example shows how to pass a lambda to a generic algorithm and how objects resulting from a lambda expression can be stored in std::function objects.*/
        {'+', [](const int f, const int s){return f+s;}},
        {'-', [](const int f, const int s){return f-s;}},
        {'*', [](const int f, const int s){return f*s;}},
        {'/', [](const int f, const int s){return f/s;}}
        };

        stack<int, vector<int>> Numbs;
        
        for(const string& token : tokens){

            // https://en.cppreference.com/w/cpp/string/byte/ispunct
            if(token.size() == 1 && ispunct(token.front())){ // "token.size() == 1 &&" необходим чтобы найти множество символов: {1,2,...,9,+,-,*,/}. После чего ispunct из них выбирает операцию

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
