class Solution {
public:
    std::vector<int> partitionLabels(std::string_view S) {

        // CharToLastID[IdxChar] -> index of S where char occurs CharToLastID
        std::array<int, 26> CharToLastID; CharToLastID.fill(0);
        for (int i = 0; i < S.length(); ++i){
            CharToLastID[S[i] - 'a'] = i; // "s consists of lowercase English letters."
        }
            

        int EndCurrentChunk  = 0; // конец текущего раздела
        int StartCurrentChunk = 0; // начало текущего раздела, начинается с 0

        std::vector<int> ans;
        for (int i = 0; i < S.length(); ++i) {
            EndCurrentChunk = std::max(EndCurrentChunk, CharToLastID[S[i] - 'a']);

            if (i == EndCurrentChunk) { // S[i] в разделе встречается последний раз, j < i также встречались до него ввиду использования max в EndCurrentChunk
                ans.push_back(i - StartCurrentChunk + 1); // длина текущего раздела
                StartCurrentChunk = i + 1; // указываем на следующий символ, начало нового раздела
            }
        }
        return ans;
    }
};


/*
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> partitionLabels(std::string S) {
        std::vector<int> CharToLastID(26, 0);
        for (int i = 0; i < S.length(); ++i) {
            CharToLastID[S[i] - 'a'] = i;
        }

        int j = 0, anchor = 0;
        std::vector<int> ans;
        for (int i = 0; i < S.length(); ++i) {
            j = std::max(j, CharToLastID[S[i] - 'a']);
            if (i == j) {
                ans.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return ans;
    }
};
*/
