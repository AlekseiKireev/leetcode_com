/*
Time complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool isPalindrome(string_view S) {
        
        const int SizeS = S.size();

        // LeftPtr < RightPtr -- важно именно такое условие! При четной длине не выполняется LeftPtr != RightPtr
        for(int LeftPtr = 0, RightPtr = SizeS - 1; LeftPtr < RightPtr; ++LeftPtr, --RightPtr){

/* isalnum --> 
s = "0P"
Expected false
https://ru.wikipedia.org/wiki/Isalnum
*/
            
            for(; LeftPtr < RightPtr && isalnum(S[LeftPtr]) == false ; ++LeftPtr);

            for(; LeftPtr < RightPtr && isalnum(S[RightPtr]) == false ; --RightPtr);

            if( tolower(S[LeftPtr]) != tolower(S[RightPtr]) ){return false;}
        }

        return true;

    }
};
