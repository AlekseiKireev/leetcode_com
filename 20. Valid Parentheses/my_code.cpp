class Solution {
public:
    bool isValid(string_view s) {
        
        if(s.empty()){return true;}
        if(s.size() % 2){return false;}

        unordered_map<char, char> OpenToClosed = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        
        stack<char, vector<char>> OpenBrackets; // https://en.cppreference.com/w/cpp/container/stack --> template< class T, class Container = std::deque<T> > class stack;

        for(int i = 0; i < s.size(); ++i){
            
            // "!OpenBrackets.empty() &&" необходимо на случай, например, таких входных данных: "()()[]" -- то есть при i = 1 уже будет пустым OpenBrackets. 
            // Также при i = 0 позваляет перейти к "OpenBrackets.push(s[i]);"
            
            if(!OpenBrackets.empty() && s[i] == OpenToClosed[OpenBrackets.top()] ){ 
                OpenBrackets.pop(); // удаляем, так как на вершине стека лежит открывающая скобка, в то время как в s[i] лежит соответст-я закрывающая скобка
            }
            else{ // если "s[i] != OpenToClosed[OpenBrackets.top()]", то значит есть, например, конструкция вида: ([]) -- то есть вподряд идет несколько открывающих скобок
                OpenBrackets.push(s[i]);
            }
        }

        return OpenBrackets.empty();
    }
};
