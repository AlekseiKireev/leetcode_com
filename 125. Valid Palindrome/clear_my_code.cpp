class Solution {
public:
    bool isPalindrome(string_view S) {
        
        const int SizeS = S.size();

        for(int LeftPtr = 0, RightPtr = SizeS - 1; LeftPtr < RightPtr; ++LeftPtr, --RightPtr){

            for(; LeftPtr < RightPtr && isalnum(S[LeftPtr]) == false ; ++LeftPtr);

            for(; LeftPtr < RightPtr && isalnum(S[RightPtr]) == false ; --RightPtr);

            if( tolower(S[LeftPtr]) != tolower(S[RightPtr]) ){return false;}
        }

        return true;

    }
};
