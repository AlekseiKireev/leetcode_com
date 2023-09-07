class Solution {

private:

bool ChechkvalidPalindrome(string_view s, int LeftPtr, int RightPtr){

    while(LeftPtr < RightPtr){

        if(s[LeftPtr] == s[RightPtr]){
            ++LeftPtr;
            --RightPtr;
        }else{
            return false;
        }

    }    
    return true;
}

public:
    bool validPalindrome(string_view s) {
        
        int LeftPtr = 0;
        int RightPtr = s.size() - 1;

        while(LeftPtr < RightPtr){

            if(s[LeftPtr] == s[RightPtr]){
                ++LeftPtr;
                --RightPtr;
            }else{
                return (ChechkvalidPalindrome(s, LeftPtr + 1, RightPtr) || ChechkvalidPalindrome(s, LeftPtr, RightPtr - 1));
            }

        }

        return true;
    }
};
