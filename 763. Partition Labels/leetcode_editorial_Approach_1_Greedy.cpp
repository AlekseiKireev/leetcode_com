/*
Time Complexity: O(N)
Space Complexity: O(alphabet)
*/
class Solution {
public:
    std::vector<int> partitionLabels(std::string_view S) {

        // CharToLastID[IdxChar] -> index of S where char occurs CharToLastID
        // 26 --> "s consists of lowercase English letters."
        std::array<int, 26> CharToLastID; CharToLastID.fill(0);
        for (int i = 0; i < S.length(); ++i){
            CharToLastID[S[i] - 'a'] = i; // "s consists of lowercase English letters."
        }
            

        int EndCurrentChunk  = 0; // конец текущего раздела
        int StartCurrentChunk = 0; // начало текущего раздела, начинается с 0

        std::vector<int> ans;
        for (int i = 0; i < S.length(); ++i) {
            EndCurrentChunk = std::max(EndCurrentChunk, CharToLastID[S[i] - 'a']); // сдвигаем ПРАВЫЙ указатель

            if (i == EndCurrentChunk) { // S[i] в разделе встречается последний раз, j < i также встречались до него ввиду использования max в EndCurrentChunk
                
                ans.push_back(EndCurrentChunk - StartCurrentChunk + 1); // длина текущего раздела

                // сдвигаем ЛЕВЫЙ указатель
                StartCurrentChunk = i + 1; // указываем на следующий символ, начало нового раздела
            }
            
        }
        return ans;
    }
};


/*
class Solution {
public:
    vector<int> partitionLabels(string Str) {
        
        int STR_SIZE = Str.size();

        array<int, 128> CharToLastIdx; //CharToLastIdx.fill(0);
        for(int i = 0; i < STR_SIZE; ++i){
            CharToLastIdx[Str[i]] = i;
        }

        int EndCurrentChunk  = 0; 
        int StartCurrentChunk = 0; 
        vector<int> LengthChanck; LengthChanck.reserve(STR_SIZE);

        for(int i = 0; i < STR_SIZE; ++i){

            EndCurrentChunk = max(EndCurrentChunk, CharToLastIdx[Str[i]]);

            if(EndCurrentChunk == i){
                LengthChanck.push_back(EndCurrentChunk -StartCurrentChunk + 1);
                StartCurrentChunk = i + 1;
            }
        }

        return LengthChanck;

    }
};
*/
