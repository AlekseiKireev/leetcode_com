class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int Max1 = INT_MIN;
        int Max2 = INT_MIN;

        for(int n : nums){

            if(Max1<= n){
                Max2 = Max1;
                Max1 = n;
                
            }else if(Max2 <= n){
                Max2 = n;
            }
        }

        return((Max1-1)*(Max2-1));
    }

};
