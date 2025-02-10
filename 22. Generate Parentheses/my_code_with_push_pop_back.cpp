/*
Time complexity: O(\frac{4^n}{\sqrt{n}}) : O(\frac{4^n}{n\sqrt{n}}) -- асимптотика количества ПСП == Числа Каталана. 
При каждом push_back происходит копирование
Space complexity: O(n)
*/    
class Solution {

private:

vector<string> BBS;// Balanced Bracket Sequences
int N;
string STACK = {};

private:

    size_t Factorial(int n){
        if(n == 0){return 1;}
        return (n * Factorial(n - 1));
    }

    // https://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D1%80%D0%B0%D0%B2%D0%B8%D0%BB%D1%8C%D0%BD%D1%8B%D0%B5_%D1%81%D0%BA%D0%BE%D0%B1%D0%BE%D1%87%D0%BD%D1%8B%D0%B5_%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8#.D0.A0.D0.B5.D0.BA.D1.83.D1.80.D1.81.D0.B8.D0.B2.D0.BD.D1.8B.D0.B9_.D0.B0.D0.BB.D0.B3.D0.BE.D1.80.D0.B8.D1.82.D0.BC_.D0.BF.D0.BE.D0.BB.D1.83.D1.87.D0.B5.D0.BD.D0.B8.D1.8F_.D0.BB.D0.B5.D0.BA.D1.81.D0.B8.D0.BA.D0.BE.D0.B3.D1.80.D0.B0.D1.84.D0.B8.D1.87.D0.B5.D1.81.D0.BA.D0.BE.D0.B3.D0.BE_.D0.BF.D0.BE.D1.80.D1.8F.D0.B4.D0.BA.D0.B0 
    void MakeBalancedBracket(int CountOpenBracket, int CountCloseBracket){

        // https://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D1%80%D0%B0%D0%B2%D0%B8%D0%BB%D1%8C%D0%BD%D1%8B%D0%B5_%D1%81%D0%BA%D0%BE%D0%B1%D0%BE%D1%87%D0%BD%D1%8B%D0%B5_%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8#.D0.90.D0.BB.D0.B3.D0.BE.D1.80.D0.B8.D1.82.D0.BC_.D0.BF.D1.80.D0.BE.D0.B2.D0.B5.D1.80.D0.BA.D0.B8_.D0.BF.D1.80.D0.B0.D0.B2.D0.B8.D0.BB.D1.8C.D0.BD.D0.BE.D1.81.D1.82.D0.B8_.D1.81.D0.BA.D0.BE.D0.B1.D0.BE.D1.87.D0.BD.D0.BE.D0.B9_.D0.BF.D0.BE.D1.81.D0.BB.D0.B5.D0.B4.D0.BE.D0.B2.D0.B0.D1.82.D0.B5.D0.BB.D1.8C.D0.BD.D0.BE.D1.81.D1.82.D0.B8      
        assert(CountCloseBracket <= CountOpenBracket); // не встречалось закрывающих скобок, для которых не было соответствующих открывающих
        if(CountOpenBracket + CountCloseBracket == 2*N){ // все открывающие скобки закрыты, при этом нет лишних закрытых скобок
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
        
        // https://neerc.ifmo.ru/wiki/index.php?title=%D0%A7%D0%B8%D1%81%D0%BB%D0%B0_%D0%9A%D0%B0%D1%82%D0%B0%D0%BB%D0%B0%D0%BD%D0%B0#.D0.90.D0.BD.D0.B0.D0.BB.D0.B8.D1.82.D0.B8.D1.87.D0.B5.D1.81.D0.BA.D0.B0.D1.8F_.D1.84.D0.BE.D1.80.D0.BC.D1.83.D0.BB.D0.B0
        BBS.reserve(Factorial(2*n) / Factorial(n) / Factorial(n) / (n + 1));
        N = n;
        
        MakeBalancedBracket(0,0);
        return BBS;
    }
};
