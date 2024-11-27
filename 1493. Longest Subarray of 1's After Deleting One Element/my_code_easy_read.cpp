class Solution {
public:
    int longestSubarray(vector<int>& Nums, int CntUpdZero = 1) {
        
        int Ans = 0; 

        int CurCntUpdZero = 0;

        for(int L = 0, R = 0; R < Nums.size(); ++R){
            
            CurCntUpdZero += (Nums[R] == 0);

            for(;CurCntUpdZero == CntUpdZero + 1  && L < R; ++L){
            
                CurCntUpdZero -= (Nums[L] == 0);            
            }

            Ans = max(Ans, R - L + 1);
        }

        return Ans - CntUpdZero;
    }
    
};
