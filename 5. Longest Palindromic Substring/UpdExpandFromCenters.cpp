/*
В этой реализации, в сравнении с ExpandFromCenters.cpp, возвращаются индексы, вместо строки, что способствует оптимизации
В обоих случаях 
O(n^2) по времени
O(1) по памяти
*/
class Solution {
public:
    pair<int, int> CheckOnPalindrom(int left, int right, string& s) {

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        // сдвиг обсуловлен тем, что в окно {s[left], ..., s[right]} не беруться крайние символы, так как s[left] != s[right]
        return {left + 1, right - 1};
    }

    int GetSize(pair<int, int> Idx){
        return Idx.second - Idx.first + 1;
    }

    string longestPalindrome(string& s) {
        
        pair<int, int> IdxAns = {0,0};

        for (int i = 0; i < s.size(); i++) {

            auto odd = CheckOnPalindrom(i, i, s); // нечетная длина палиндрома
            if (GetSize(odd) > GetSize(IdxAns)) { // обновляем ответ
                IdxAns = odd;
            }

            auto even = CheckOnPalindrom(i, i + 1, s); // четная длина палиндрома
            if (GetSize(even) > GetSize(IdxAns)) { // обновляем ответ
                IdxAns = even;
            }
        }

        return s.substr(IdxAns.first, GetSize(IdxAns));
    }
};
