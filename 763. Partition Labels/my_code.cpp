class Solution {
public:

    vector<int> partitionLabels(const string_view s) {
        
        vector<int> SizeParts;

        vector<int> CharToEndIdx(26); // "s consists of lowercase English letters."
        for(int i = 0; i < s.size(); ++i){CharToEndIdx[s[i] - 'a'] = i;}

        int PrevIdxEndPart = -1; /* "-1" необходим для удобства измерения расстояния между индексами. 
                                    Если бы "PrevIdxEndPart = 0", то имело бы место стркоа: "SizeParts.push_back(IdxEndPart -   PrevIdxEndPart + 1);"*/
        int IdxEndPart = 0;

        for(int i = 0; i < s.size(); ++i){ // сдвиг левого указтеля

            // если i < IdxEndPart и при этом IdxEndPart < CharToEndIdx[s[i] - 'a'], значит в исследуемом чанке, в рамках индексов {IdxEndPart, IdxEndPart}, есть 
            // символ для которого не выполняется условие " each letter appears in at most one part." -- ибо есть еще такой символ по инексу CharToEndIdx[s[i] - 'a']
            // поэтому IdxEndPart надо обновить до CharToEndIdx[s[i] - 'a']
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
