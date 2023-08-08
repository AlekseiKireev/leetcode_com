class Solution {
public:

    vector<int> partitionLabels(const string_view s) {
        
        vector<int> SizeParts;

        vector<int> CharToEndIdx(26); // "s consists of lowercase English letters."
        for(int i = 0; i < s.size(); ++i){CharToEndIdx[s[i] - 'a'] = i;}

        int PrevIdxEndPart = -1; /* "-1" необходим для того для удобства измерения расстояния между индексами. 
                                    Если бы "PrevIdxEndPart = 0", то имело бы место стркоа: "SizeParts.push_back(IdxEndPart -   PrevIdxEndPart + 1);"*/
        int IdxEndPart = 0;

        for(int i = 0; i < s.size(); ++i){ // сдвиг левого указтеля
           
            IdxEndPart = max(IdxEndPart, CharToEndIdx[s[i] - 'a']); // сдвиг правого указтеля

            assert(i <= IdxEndPart); 

            if(IdxEndPart == i){ // дошли до конца чанка. Конец находится по индексу i

                SizeParts.push_back(IdxEndPart - PrevIdxEndPart);
                PrevIdxEndPart = IdxEndPart;
                
            }

        }

        return SizeParts;

    }
};
