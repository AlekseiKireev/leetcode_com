class Solution {

public:

    string longestPalindrome(string s) {
        
        const int n = s.size();
        vector<vector<bool>> DP (n, vector<bool>(n));

        for(int i = 0; i < n; ++i){DP[i][i] = true;}

        // "1 <= s.length <= 1000"
        int LeftBorder = 0;
        int RightBorder = 0;

        for(int i = 0; i < n - 1; ++i){ // "Example 2:" демонстрирует, что уже с этого цикла надо обрабатывать ответ

            if(s[i] == s[i + 1]){
                DP[i][i + 1] = true;
                LeftBorder = i;
                RightBorder = i + 1;
            }

        }

        for(int dj = 2; dj < n; ++dj){
            for(int i = 0; i < n  - dj; ++i){
                int j = i + dj;

                assert(i <= j);

                if(s[i] == s[j] && DP[i + 1][j - 1]){ // {s[i], ..., s[j]} is palindrome
                    DP[i][j] = true;
                    LeftBorder = i;
                    RightBorder = j;
                }

            }            
        }

        return s.substr(LeftBorder, RightBorder - LeftBorder + 1);

    }

};
