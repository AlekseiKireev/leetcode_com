class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int F_s = text1.size();
        int S_s = text2.size();
        // dp[i][j] := the length of LCS(text1[0..i), text2[0..j))
        // +1 необходим для того, чтобы в условмом операторе цикла можно было обращаться к предыдущему индексу
        vector<vector<int>> DP(F_s + 1,vector<int>(S_s + 1, 0));

        for(int f = 1; f < F_s + 1; ++f){
            for(int s = 1; s < S_s + 1; ++s){

                if(text1[f-1] == text2[s-1]){ // есть общий символ, увеличиваем ответ на +1 для LCS(text1[0..i-1), text2[0..j-1))
                    DP[f][s] = DP[f-1][s-1] + 1;
                }else{ // максимизируем LCS, анализируя  LCS(text1[0..i-1), text2[0..j)) и  LCS(text1[0..i), text2[0..j-1))
                    DP[f][s] = max(DP[f-1][s], DP[f][s-1]);
                }

            }
        }

        return DP[F_s][S_s];
    }
};
