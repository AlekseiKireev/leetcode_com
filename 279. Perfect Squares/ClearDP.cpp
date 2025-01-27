class Solution {
public:
    int numSquares(int n) {
        
        vector<int> DP(n+1, 5);
        DP[1] = 1;
        DP[0] = 0;
        for(int i = 0; i < DP.size(); ++i){
            for(int t = 0; t*t <= i; ++t){
                DP[i] = min(DP[i], DP[i - t*t] + 1);
            }
        }

        return DP.back();
    }
};
