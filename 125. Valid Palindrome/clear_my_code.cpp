class Solution {
public:
    bool isPalindrome(string_view S) {
        
        const int SizeS = S.size();

        // LeftPtr < RightPtr -- важно именно такое условие!
        for(int LeftPtr = 0, RightPtr = SizeS - 1; LeftPtr < RightPtr; ++LeftPtr, --RightPtr){

/* isalnum --> 
s = "0P"
Expected false
*/
            
            for(; LeftPtr < RightPtr && isalnum(S[LeftPtr]) == false ; ++LeftPtr);

            for(; LeftPtr < RightPtr && isalnum(S[RightPtr]) == false ; --RightPtr);

            if( tolower(S[LeftPtr]) != tolower(S[RightPtr]) ){return false;}
        }

        return true;

    }
};
