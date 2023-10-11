class Solution {

bool isPalindrome(const string& S)
{

    for (int i = 0; i < S.size() / 2; i++) {

        if (S[i] != S[S.size() - i - 1]) {return false;}
    }

    return true;
}

public:
    string longestPalindrome(const string& s) {
        
        string LPS  {s.front()}; // <-- "1 <= s.length <= 1000"

        for (int i = 0; i < s.size(); i++) {
                for (int j = i + 1; j <= s.size(); j++) {
                    
                    if(isPalindrome({s.begin() + i, s.begin() + j}) && LPS.size() < j - i){
                       LPS = {s.begin() + i, s.begin() + j};
                    }
            }
        }

        return LPS;
    }
};
