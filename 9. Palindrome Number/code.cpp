class Solution {
public:
    bool isPalindrome(int x) {
        
        // x = -121   Expected false
        if (x < 0) {
            return false;
        }

        int Reversed = 0;
        int Buf = x;
        while(Buf != 0){

            Reversed = Reversed*10 + Buf%10;
            Buf /=10;

        }

        return (Reversed == x);
    }
};
