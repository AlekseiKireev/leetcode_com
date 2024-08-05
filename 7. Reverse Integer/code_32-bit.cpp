class Solution {
public:
    int reverse(int x) {
        
        int A = 0;

        while(x != 0){

            if(A > INT_MAX/10  || A < INT_MIN/10){
                return 0;
            }
            A = A*10+x%10; // A > INT_MAX/10  || A < INT_MIN/10 : * 10 <--> A*10 > INT_MAX || A*10 < INT_MIN

            x/=10;
        }

        if(x<0){
            A=-A;
        }
        return   A;

    }
};
