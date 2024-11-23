/*
Time complexity: O(n)
Space complexity: O(alphabet)
*/
class Solution {
public:
    bool isIsomorphic(string_view S, string_view T) {

        if(S.size() != T.size()){return false;}
        /* // good!
        array<char, 128> CharS_to_CharT; CharS_to_CharT.fill(-1);
        array<char, 128> CharT_to_CharS; CharT_to_CharS.fill(-1);
        */
        array<int, 128> CharS_to_CharT; CharS_to_CharT.fill(-1); // отображаем элемент S[k] из множества S в элемент T[k] из множества T 
        array<int, 128> CharT_to_CharS; CharT_to_CharS.fill(-1); // отображаем элемент T[k] из множества T в элемент S[k] из множества S 


        for(int i = 0; i < S.size(); ++i){ // S.size() == T.size()

            // работает и с этим условным оператором и без
            if(CharS_to_CharT[S[i]] * CharT_to_CharS[T[i]] < 0){return false;} // нарушено условие биекции: есть отображение элемента из S в T, но нет из T в S (или наоборот)

            if(CharS_to_CharT[S[i]] == -1 && CharT_to_CharS[T[i]] == -1){ // устанавливаем биективную связь
                CharS_to_CharT[S[i]] = T[i];
                CharT_to_CharS[T[i]] = S[i];                
            }
            else{ // CharS_to_CharT[S[i]] != -1 && CharT_to_CharS[T[i]] != -1 <-- из первого и второго условного оператора 

                // проверяем условие соблюдения биекции: если S[i] --> T[i], то T[i] --> S[i]
                if(CharS_to_CharT[S[i]] != T[i] || CharT_to_CharS[T[i]] != S[i]){return false;}
            }


        }

        return true;

    }
};
