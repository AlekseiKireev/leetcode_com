/*
Time complexity: O(\frac{4^n}{\sqrt{n}}) : O(\frac{4^n}{n\sqrt{n}}) -- асимптотика количества ПСП == Числа Каталана. 
При каждом push_back происходит копирование
Space complexity: O(n)
*/    
class Solution {

private:

vector<string> BBS;
int N;
string STACK = {};

private:

    size_t Factorial(int n){
        if(n == 0){return 1;}
        return (n * Factorial(n - 1));
    }

    void MakeBalancedBracket(int CountOpenBracket, int CountCloseBracket){

        assert(CountCloseBracket <= CountOpenBracket); 
        if(CountOpenBracket + CountCloseBracket == 2*N){ 
            BBS.push_back(STACK);
            return;
        }

        if(CountOpenBracket < N){
            STACK.push_back('(');
            MakeBalancedBracket(CountOpenBracket + 1, CountCloseBracket);
            STACK.pop_back();
        }

        if(CountCloseBracket < CountOpenBracket){
            STACK.push_back(')');
            MakeBalancedBracket(CountOpenBracket, CountCloseBracket + 1);
            STACK.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {

        BBS.reserve(Factorial(2*n) / Factorial(n) / Factorial(n) / (n + 1));
        N = n;
        
        MakeBalancedBracket(0,0);
        return BBS;
    }
};
