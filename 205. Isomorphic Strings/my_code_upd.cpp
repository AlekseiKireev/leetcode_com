class Solution {

public:

    bool isIsomorphic(string S, string T) {
        
        const int SIZE = S.size();
        
        array<char, 128> S_ch_To_T_ch; 
        S_ch_To_T_ch.fill('\0');
        
        unordered_set<char> UsedCharT; // <-- " Wrong Answer 37 / 44 testcases   Input s = "badc" t = "baba" "
        
        for(int i = 0 ; i < SIZE;++i){

            if(UsedCharT.count(T[i]) == 1 && S_ch_To_T_ch[S[i]] == '\0'){
                return false; // нарушена биекция при отображении S в T
            }

            if(S_ch_To_T_ch[S[i]] == '\0' &&  UsedCharT.count(T[i]) == 0){
              
                S_ch_To_T_ch[S[i]] = T[i];                
                UsedCharT.insert(T[i]);
              
                }

                S[i] =  S_ch_To_T_ch[S[i]];
            
        }

        return S == T;

    }

};
