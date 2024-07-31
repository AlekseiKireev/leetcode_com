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

            for(; CountChFromAngrInSW == Angr.size(); ++LeftPtr){ 

                if(RightPtr - LeftPtr + 1 == Angr.size()){
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
