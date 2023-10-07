class Solution {

private:

vector<string> BBS;
string STACK = {};
int N; 

void MakeBBS(int CountOpenBracket, int CountCloseBracket){

    assert(CountCloseBracket <= CountOpenBracket);
    if(CountOpenBracket + CountCloseBracket == 2 * N){
        BBS.push_back(STACK);
        return;
    }

    if(CountOpenBracket < N){
        STACK.push_back('(');
        MakeBBS(CountOpenBracket + 1, CountCloseBracket);
        STACK.pop_back();
    }

    if(CountCloseBracket < CountOpenBracket){
        STACK.push_back(')');
        MakeBBS(CountOpenBracket, CountCloseBracket + 1);
        STACK.pop_back();
    }    

}

public:
    vector<string> generateParenthesis(int n) {
        N = n;
        MakeBBS(0,0);
        return BBS;
    }
};
