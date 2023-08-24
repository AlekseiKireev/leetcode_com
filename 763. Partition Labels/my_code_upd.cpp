class Solution {
public:
    vector<int> partitionLabels(string_view s) {
        
        vector<int> CharToEndIdx(26);

        for(int i = 0; i < s.size(); ++i){CharToEndIdx[s[i] - 'a'] = i;}

        vector<int> SizeParts; SizeParts.reserve(26);

        int LeftBorderChunk = -1; // инициализируем '-1', например, для входных данных вида: "a" / "abc"
        int RightBorderChunk = 0; // инициализируем '0', например, для входных данных вида: "a" / "abc"

        for(int i = 0; i < s.size(); ++i){

            RightBorderChunk = max(RightBorderChunk, CharToEndIdx[s[i] - 'a']); // ????????????????

            if(RightBorderChunk == i){ // ????????????????
                SizeParts.push_back(RightBorderChunk - LeftBorderChunk);
                LeftBorderChunk = RightBorderChunk; // LeftBorderChunk все также указывает на элемент, стоящий перед началом чанка --> p(RightBorderChunk, LeftBorderChunk) так и будет равен далее RightBorderChunk - LeftBorderChunk
            }
            
            assert(i <= RightBorderChunk);
            assert(LeftBorderChunk<= i);

        }

        SizeParts.shrink_to_fit();
        assert(SizeParts.size() <= 26);
        return SizeParts;
    }
};
