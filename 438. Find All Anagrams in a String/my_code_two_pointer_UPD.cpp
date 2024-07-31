class Solution {
public:
    vector<int> findAnagrams(string Str, string Angr) {
        
        vector<int> CharAngrToCount(128);
        for(char ch : Angr){
            --CharAngrToCount[ch]; // сумма отрицательных чисел по модулю будет равняться Angr.size()
        }

        vector<int> Idxs;
        int CountChFromAngrInSW = 0;
        for(int LeftPtr = 0, RightPtr = 0; RightPtr < Str.size(); ++RightPtr){

            if(++CharAngrToCount[Str[RightPtr]]<= 0){ 
                ++CountChFromAngrInSW;
            }

            for(; CountChFromAngrInSW == Angr.size(); ++LeftPtr){ // в окне {S[L], ..., S[R]} находятся символы из которых можнно построить Angr

                if(RightPtr - LeftPtr + 1 == Angr.size()){ // окно {S[L], ..., S[R]} имеют длину аналогичной Angr, поэтому из определения анаграмму  --> {S[L], ..., S[R]} является анаграммой Angr
                    Idxs.push_back(LeftPtr);
                }

                if(--CharAngrToCount[Str[LeftPtr]] < 0){ // CharAngrToCount[ch] >= 0 если ch не лежит в Angr
                    --CountChFromAngrInSW;
                }
            }

        }

        return Idxs;
    }
};
