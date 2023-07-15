class Solution {
public:

    //  p == Angr == Anagram
    vector<int> findAnagrams(string_view S, string_view Angr) {
        
        // DataForBuildAngr[k] --> необходимое положительное количество символов 'a' + k для построения анаграммы наподобие Angr в рамках windows == [ S[l], S[l + 1], ..., S[r] ]
        // 26 -- можщность алфавита, обусловленного улосвием задачи: "s and p consist of lowercase English letters."
        array<int, 26> DataForBuildAngr; // содержит положительное количество символов, которые необходимы для построения анаграммы наподобие Angr
        DataForBuildAngr.fill(0);

        for(char ch : Angr){++DataForBuildAngr[ch - 'a'];}

        int CountCharInWindowForBuildAngr = 0; // количество символов в window, которые лежат в Angr
        
        vector<int> Idxs;
        for(int l = 0, r = 0; r < S.size();++r){

            // ">=" так как декрементируем на месте. Именно благодаря декременту дли символов, не лежащих в Angr, имеет место неравенство: DataForBuildAngr[k] < 0
            if(--DataForBuildAngr[S[r] - 'a'] >= 0){ // если это истино, то символ DataForBuildAngr[S[r] - 'a'] хотя-бы раз встречался в Angr
                ++CountCharInWindowForBuildAngr;
            }

            // если CountCharInWindowForBuildAngr == Angr.size() -- истина, то можно утверждать, что
            //  Angr == [ Angr[0], Angr[1], ..., Angr[Angr.size() - 1] ] является мультиподмножеством windows == [ S[l], S[l + 1], ..., S[r] ]
            while(CountCharInWindowForBuildAngr == Angr.size()){
                               
                if(r - l + 1 == Angr.size()){Idxs.push_back(l);} // <--> [ Angr[0], Angr[1], ..., Angr[Angr.size() - 1] ] == [ S[l], S[l + 1], ..., S[r] ]

                // сдвигаем левый указатель. Если ++DataForBuildAngr[S[l++] - 'a'] > 0 истино, то левый указатель указывал на символ, лежащий в Angr, т.е. S[l], 
                // именно поэтому декрементируем CountCharInWindowForBuildAngr
                if(++DataForBuildAngr[S[l++] - 'a'] > 0){--CountCharInWindowForBuildAngr;}

            }

        }

        return Idxs;
    }
};
