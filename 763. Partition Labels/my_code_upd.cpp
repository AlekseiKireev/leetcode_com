class Solution {
public:
    vector<int> partitionLabels(string_view s) {
        
        vector<int> CharToEndIdx(26);

        for(int i = 0; i < s.size(); ++i){
            CharToEndIdx[s[i] - 'a'] = i;
        }

        vector<int> SizeParts; SizeParts.reserve(26);

        IdxEndPart = 0; // инициализируем нулем, например, для входных данных вида: "a" / "abc"

        for(int i = 0; i < s.size(); ++i){

            IdxEndPart = max(IdxEndPart, CharToEndIdx[s[i] - 'a']);

            if(IdxEndPart == i){

            }

        }

        SizeParts.shrink_to_fit();
        assert(SizeParts.size() <= 26);
        return SizeParts;
    }
};
