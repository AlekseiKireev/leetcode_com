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
                if(Open.empty()){
                    return false;
                }

                // нарушение: Если встретили закрывающую скобку, то последняя открывающая должна быть того же типа!
                if(OpenToClosed[Open.top()] != s[i]){
                    return false;
                }

                Open.pop();
            }                

        }

        return Open.empty(); // 94 / 98 testcases passed: Input s = "((" Expected false

    }
};
