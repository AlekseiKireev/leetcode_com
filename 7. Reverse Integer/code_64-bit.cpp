class Solution {
public:
    int reverse(int x) {
        
        long A;

        while(x != 0){
            A = A*10+x%10;
            x/=10;
        }

        if(x<0){
            A=-A;
        }
        return A > INT_MAX  || A < INT_MIN ? 0 : A;

    }
};
