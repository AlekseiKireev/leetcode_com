class Solution {
public:
    int maxPower(string s) {
        
        int LenSub = 1;
        
         //l - левый указатель 
         //r - правый указатель

        for(int l = 0, r; l < s.size() - 1; ++l){

            r = l + 1;

            if(s[l] == s[r]){

                while(r < s.size() && s[l] == s[r]){++r;}

                LenSub = max(LenSub, r - l); // почему не r - l + 1? Потому что r указывает за "substring that contains only one unique character."

                l = r - 1; // "- 1" так как после выхода их if значение l инкрементируется в цикле for, при этом в начале следующей итреации цикла l должен быть на том месте, где с прошлой итерации остался r указатель         
                }
        }

        return LenSub;
    }
};
