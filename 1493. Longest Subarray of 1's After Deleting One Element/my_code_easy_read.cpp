class Solution {
public:
    int longestSubarray(vector<int>& N, int k = 1) {

  int Ans = 0;

        int CountFlipZero = 0;

        for(int L = 0, R = 0; R < N.size(); ++R){

            if(N[R] == 0){
                ++CountFlipZero;
            }

            for(;CountFlipZero == k + 1; ++L){ // CountFlipZero == R - L + 1 - CountOne
                if(N[L] == 0){
                    --CountFlipZero;
                }                
            }

            Ans = max(Ans, R - L + 1);
        }

        return Ans - k; // разница только в этой строке в сравнение с 1004

    }
};
