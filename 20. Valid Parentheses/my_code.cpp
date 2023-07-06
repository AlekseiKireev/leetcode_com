class Solution {
public:
    bool isValid(string s) {
        
        if(s.empty()){return true;}
        if(s.size() % 2){return false;}

        unordered_map<char, char> OpenToClosed = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        stack<char> brackets; brackets.push(s.front());

        for(int i = 1; i < s.size(); ++i){

            if(!brackets.empty() && s[i] == OpenToClosed[brackets.top()] ){ // "!brackets.empty() &&" необходимо на случай, например, таких входных данных: "()()[]" -- то есть при i = 1 уже будет пустым brackets
                 brackets.pop();
            }else{
                brackets.push(s[i]);
            }
        }

        return brackets.empty();
    }
};
