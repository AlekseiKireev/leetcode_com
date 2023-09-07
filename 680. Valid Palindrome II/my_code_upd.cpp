class Solution {

private:

bool ChechkvalidPalindrome(string_view s, int LeftPtr, int RightPtr){

    for(;LeftPtr < RightPtr; ++LeftPtr, --RightPtr){

        if(s[LeftPtr] != s[RightPtr]){return false;}

    }    
    return true;
}

public:
    bool validPalindrome(string_view s) {
        

        for( int LeftPtr = 0, RightPtr = s.size() - 1;LeftPtr < RightPtr; ++LeftPtr, --RightPtr){

            if(s[LeftPtr] != s[RightPtr]){
 
                return (ChechkvalidPalindrome(s, LeftPtr + 1, RightPtr) || ChechkvalidPalindrome(s, LeftPtr, RightPtr - 1));
            }

        }

        return true;
    }
};
