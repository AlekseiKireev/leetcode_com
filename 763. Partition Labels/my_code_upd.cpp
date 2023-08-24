class Solution {
public:
    vector<int> partitionLabels(string_view s) {
        
        vector<int> CharToEndIdx(26);

        for(int i = 0; i < s.size(); ++i){CharToEndIdx[s[i] - 'a'] = i;}

        vector<int> SizeParts; SizeParts.reserve(26);

        int LeftBorderChunk = -1; // инициализируем '-1', например, для входных данных вида: "a" / "abc"
        int RightBorderChunk = 0; // инициализируем '0', например, для входных данных вида: "a" / "abc"

        for(int i = 0; i < s.size(); ++i){
            /* Утверждения:
             LeftBorderChunk указывает на элемент, предшествующий первому в исследуемом чанке
             i == LeftPtr
             RightBorderChunk == RightPtr -- указывают на потенциальынй конец чанка

             i и RightBorderChunk в одном чанке находятся всегда

             CharToEndIdx[s[i] - 'a'] -- указывают на потенциальынй конец чанка, в котором последний раз встречается s[i]
            */
            RightBorderChunk = max(RightBorderChunk, CharToEndIdx[s[i] - 'a']); // обновляем правую крайницу чанка в поисках крайней, максимальной

            if(RightBorderChunk == i){ // Максимальное значение правой границы чанка совпало с текущей левой границей <--> " each letter appears in at most one part." == каждая буква появлялась не более чем в одной части.
            
                SizeParts.push_back(RightBorderChunk - LeftBorderChunk); // искомое
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
