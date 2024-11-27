/*
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {

public:

    int longestOnes(vector<int>& Nums, int MaxCntFlipZero) {
        
        int Ans = 0; // если Ans = 1 --> Input nums = [0,0,0,0] MaxCntFlipZero = 0   Output 1 Expected 0

        int CurCntFlipZero = 0;

        for(int L = 0, R = 0; R < Nums.size(); ++R){
            
            CurCntFlipZero += (Nums[R] == 0);

            for(;CurCntFlipZero == MaxCntFlipZero + 1 && L <= R; ++L){
            
                CurCntFlipZero -= (Nums[L] == 0);            
            }

            Ans = max(Ans, R - L + 1);
        }

        return Ans;
    }

};
