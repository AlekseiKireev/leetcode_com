class Solution {
public:
    bool isIsomorphic(string S, string T) {
        
        array<int, 128> CharS_to_CharT; CharS_to_CharT.fill(-1);
        array<int, 128> CharT_to_CharS; CharT_to_CharS.fill(-1);


        for(int i = 0; i < S.size(); ++i){

            // работает и с этой строкой и без
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
