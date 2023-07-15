class Solution {
public:

    //  p == Angr == Anagram
    vector<int> findAnagrams(string_view S, string_view Angr) {
        
        // DataWindowForBuildAngr[k] --> необходимое положительное количество символов 'a' + k для построения анаграммы наподобие Angr в рамках window == [ S[l], S[l + 1], ..., S[r] ]
        // 26 -- можщность алфавита, обусловленного улосвием задачи: "s and p consist of lowercase English letters."
        array<int, 26> DataWindowForBuildAngr; // содержит положительное количество символов, которые необходимы для построения анаграммы наподобие Angr
        DataWindowForBuildAngr.fill(0);

        for(char ch : Angr){++DataWindowForBuildAngr[ch - 'a'];}

        int CountCharInWindowForBuildAngr = 0; // количество символов в window, которые лежат в Angr
        
        vector<int> Idxs;
        for(int l = 0, r = 0; r < S.size();++r){

            // ">=" так как декрементируем на месте. Именно благодаря декременту дли символов, не лежащих в Angr, имеет место неравенство: DataWindowForBuildAngr[k] < 0
            if(--DataWindowForBuildAngr[S[r] - 'a'] >= 0){ // если это истино, то символ DataWindowForBuildAngr[S[r] - 'a'] хотя-бы раз встречался в Angr
                ++CountCharInWindowForBuildAngr;
            }

            // если CountCharInWindowForBuildAngr == Angr.size() -- истина, то можно утверждать, что
            //  Angr == [ Angr[0], Angr[1], ..., Angr[Angr.size() - 1] ] является мультиподмножеством windows == [ S[l], S[l + 1], ..., S[r] ]
            while(CountCharInWindowForBuildAngr == Angr.size()){

                // этот условный оператор должен в начале цикла, действиткельно: S = cabrw, Angr = abc
                if(r - l + 1 == Angr.size()){Idxs.push_back(l);} // <--> [ Angr[0], Angr[1], ..., Angr[Angr.size() - 1] ] == [ S[l], S[l + 1], ..., S[r] ]

                // сдвигаем левый указатель. Если ++DataWindowForBuildAngr[S[l++] - 'a'] > 0 истино, то левый указатель указывал на символ, лежащий в Angr, т.е. S[l], 
                // именно поэтому декрементируем CountCharInWindowForBuildAngr
                if(++DataWindowForBuildAngr[S[l++] - 'a'] > 0){--CountCharInWindowForBuildAngr;}

            }

        }

        return Idxs;
    }
};
