class Solution {
public:
    pair<int, int> CheckOnPalindrom(int i, int j, string s) {
        int left = i;
        int right = j;

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

    string longestPalindrome(string s) {
        
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
