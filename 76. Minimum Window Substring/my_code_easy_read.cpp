    // https://en.cppreference.com/w/cpp/language/ascii
    const int POWER_ENCODING = 128; // s and t consist of uppercase and lowercase English letters.

class Solution {



public:
    string minWindow(string S, string T) {
        
        const int S_SIZE = S.size();
        const int T_SIZE = T.size();

        if(S_SIZE < T_SIZE){
            return "";
        }

        array<int, POWER_ENCODING>AnagramT; AnagramT.fill(0);

        for(char t : T){
            --AnagramT[t];
        }


        int LeftPtr = 0, RightPtr = 0; 

        // "+1" ввиду  Wrong Answer 251 / 268  Input s = "a" t = "a" Use Testcase Output "" Expected "a"
        int MinimumSizeSW = S_SIZE + 1; // s = "AONBONC", t = "ABC"
        int LeftPtrOnSubstr = -1; // почему не 0? Пример: Wrong Answer 224 / 268 Input s = "a" t = "b" Use Testcase Output "a" Expected ""

        for(int CountCharFromT = 0; RightPtr < S_SIZE; ++RightPtr){

            if(++AnagramT[S[RightPtr]] <= 0){
                ++CountCharFromT;
            }

            for(; CountCharFromT == T_SIZE; ++LeftPtr){
                
                // обновление ответа
                if(RightPtr - LeftPtr + 1 < MinimumSizeSW){
                    LeftPtrOnSubstr = LeftPtr;
                    MinimumSizeSW = RightPtr - LeftPtr + 1;
                }

                // выход из цикла
                if(--AnagramT[S[LeftPtr]] < 0){
                    --CountCharFromT;
                }


            }

        }

        return LeftPtrOnSubstr == -1 ? "" : S.substr(LeftPtrOnSubstr, MinimumSizeSW);

    }
};
