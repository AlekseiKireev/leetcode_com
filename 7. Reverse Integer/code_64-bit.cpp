class Solution {
public:
    int reverse(int x) {
        
        long A = 0;

        while(x != 0){
            A = A*10+x%10;
            x/=10;
        }

        return A > INT_MAX  || A < INT_MIN ? 0 : A;

    }
};
