class Solution {

private:

    vector<string> BBS;
    int N;

    void MakeBalancedBracket(int CountOpenBracket, int CountCloseBracket, string STACK = {}){

        assert(CountCloseBracket <= CountOpenBracket); 
        if(CountOpenBracket + CountCloseBracket == 2*N){ 
            BBS.push_back(move(STACK));
            return;
        }

        if(CountOpenBracket < N){
            MakeBalancedBracket(CountOpenBracket + 1, CountCloseBracket, STACK + '(');
        }

        if(CountOpenBracket > CountCloseBracket){
            MakeBalancedBracket(CountOpenBracket, CountCloseBracket + 1, STACK + ')');
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        
        N = n;
        MakeBalancedBracket(0,0);
        return BBS;
    }
};
