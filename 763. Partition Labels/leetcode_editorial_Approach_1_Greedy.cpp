class Solution {
public:
    std::vector<int> partitionLabels(std::string_view S) {

        // last[IdxChar] -> index of S where char occurs last
        std::array<int, 26> last; last.fill(0);
        for (int i = 0; i < S.length(); ++i){
            last[S[i] - 'a'] = i;
        }
            

        int EndCurrentChunk  = 0; // конец текущего раздела
        int StartCurrentChunk = 0; // начало текущего раздела, начинается с 0

        std::vector<int> ans;
        for (int i = 0; i < S.length(); ++i) {
            EndCurrentChunk = std::max(EndCurrentChunk, last[S[i] - 'a']);

            if (i == EndCurrentChunk) {
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
        std::vector<int> last(26, 0);
        for (int i = 0; i < S.length(); ++i) {
            last[S[i] - 'a'] = i;
        }

        int j = 0, anchor = 0;
        std::vector<int> ans;
        for (int i = 0; i < S.length(); ++i) {
            j = std::max(j, last[S[i] - 'a']);
            if (i == j) {
                ans.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return ans;
    }
};
*/
