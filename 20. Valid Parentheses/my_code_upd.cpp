/*
Time complexity: O(s.size())
Space complexity: O(s.size())
*/    
class Solution {

unordered_map<char,char> OpenToClosed = { {'(', ')'}, {'{', '}'}, {'[',']'} };

public:
    bool isValid(string s) {
        
        const int SIZE = s.size();
        if(SIZE%2 == 1){return false;}
        
        stack<char,vector<char>> Open;

        for(int i = 0; i < SIZE; ++i){

            if(OpenToClosed.count(s[i])){

                Open.push(s[i]);

            }else{ // s[i] -- закрывающая скобка

                // нарушение: для открывающей скобки не существует открывающей
                // Ex: {()}]
                if(Open.empty()){return false;}

                // нарушение: Если встретили закрывающую скобку, то последняя на вершине стека открывающая должна быть того же типа!
                // Ex: {(}
                if(OpenToClosed[Open.top()] != s[i]){return false;}

                // закрвающая скобка того же типа, удаяем ее
                // Ex: {()}
                Open.pop();
            }                

        }

        return Open.empty(); // 94 / 98 testcases passed: Input s = "((" Expected false

    }
};
