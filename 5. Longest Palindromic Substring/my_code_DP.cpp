class Solution {
public:
    string longestPalindrome(string s) {
        
        const int n = s.size();
        vector<vector<bool>> DP (n, vector<bool>(n));

        int LeftIdxAns  = 0;
        int RightIdxAns = 0;

        // обратка главной диагонали в DP
        for(int i = 0; i < n; ++i){DP[i][i] = true;} // строка {s[i],...,s[i]} является палиндромом        

        // обработка диагонали над главной в DP. Необхоим так как далее будем работать с DP[i+1][j-1], а {i+1,j-1} может оказаться под главной диагональю
        for(int i = 1; i < n; ++i){

            if(s[i-1] == s[i]){ // проверка строки {s[i-1], s[i]} на палендром
                DP[i-1][i] = true;
                LeftIdxAns= i-1;
                RightIdxAns=i;
            }

        }

        // обработка оставшихся диагоналей над главной, начиная с 2
        for(int dt = 2; dt < n; ++dt){ // для смещения 

            for(int i = 0; i < n - dt;++i){ // проход столбцам, "- dt" нужно чтобы j = i + dt не вышел за границу
                int j = i + dt;

                if(s[i] == s[j] && DP[i+1][j-1]){ // {s[i], s[i + 1],..., s[j - 1] , s[j]} is palindrome
                    DP[i][j] = true;
                    LeftIdxAns = i; RightIdxAns = j;
                }
            }

        }

        return s.substr(LeftIdxAns,RightIdxAns - LeftIdxAns + 1);
    }
};


/*class Solution {

public:

    string longestPalindrome(string s) {
        
        const int n = s.size();
        vector<vector<bool>> DP (n, vector<bool>(n));

        for(int i = 0; i < n; ++i){DP[i][i] = true;} // строка {s[i],...,s[i]} является палиндромом

        // "1 <= s.length <= 1000"
        // границы ответа, обновляются если найдет палиндром большей длины, чем RightBorder - LeftBorder + 1
        int LeftBorder = 0;
        int RightBorder = 0;

        for(int i = 0; i < n - 1; ++i){ // "Example 2:" демонстрирует, что уже с этого цикла надо обрабатывать указатели [ответ]

            if(s[i] == s[i + 1]){
                DP[i][i + 1] = true;
                LeftBorder = i;
                RightBorder = i + 1;
            }

        }

        // Заметим, что n  - 1 и n  - 2 строка в DP уже заполнены, при каждом последующем заполнении диагонали, в том числе заполняем еще одну строку с конца --> 
        // надо итерироваться по строкам вплоть до n  - dj строки, где 2 <= dj <= n - 1
        for(int dj = 2; dj < n; ++dj){ // смещение
            for(int i = 0; i < n  - dj; ++i){ // итерируемся по строкам, а не столбцам, как это часто бывает. 
                const int j = i + dj; // "int j = i" смещает столбец j до диагонали DP таблицы, при этом надо еще сдвинуть на фииксированный сдвиг dj, для того чтобы находится в рамках заданной диагонали

                assert(i <= j);

                if(s[i] == s[j] && DP[i + 1][j - 1]){ // {s[i], s[i + 1],..., s[j - 1] , s[j]} is palindrome
                    DP[i][j] = true;
                    LeftBorder = i;
                    RightBorder = j;
                }

            }            
        }

        return s.substr(LeftBorder, RightBorder - LeftBorder + 1);

    }

};
*/
