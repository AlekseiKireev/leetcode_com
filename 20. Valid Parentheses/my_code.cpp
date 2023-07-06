class Solution {
public:
    bool isValid(string s) {
        
        if(s.empty()){return true;}
        if(s.size() % 2){return false;}

        unordered_map<char, char> OpenToClosed = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        
        stack<char> brackets;

        for(int i = 0; i < s.size(); ++i){
            
            // "!brackets.empty() &&" необходимо на случай, например, таких входных данных: "()()[]" -- то есть при i = 1 уже будет пустым brackets. 
            // Также при i = 0 позваляет перейти к "brackets.push(s[i]);"
            
            if(!brackets.empty() && s[i] == OpenToClosed[brackets.top()] ){ 
                brackets.pop(); // удаляем, так как на вершине стека лежит открывающая скобка, в то время как в s[i] лежит соответст-я закрывающая скобка
            }
            else{ // если "s[i] != OpenToClosed[brackets.top()]", то значит есть, например, конструкция вида: ([]) -- то есть вподряд идет несколько открывающих скобок
                brackets.push(s[i]);
            }
        }

        return brackets.empty();
    }
};
