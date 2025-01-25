class Solution {
public:
    string CheckOnPalindrom(int i, int j, string s) {
        int left = i;
        int right = j;

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        // right - left - 1 = right - left + 1  - 2, где "-2" обсуловлен тем, что в окно {s[left], ..., s[right]} не беруться крайние символы, так как s[left] != s[right]
        return s.substr(left + 1, right - left - 1); 
    }

    string longestPalindrome(string s) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            string odd = CheckOnPalindrom(i, i, s); // нечетная длина палиндрома
            if (odd.size() > ans.size()) { // обновляем ответ
                ans = odd;
            }

            string even = CheckOnPalindrom(i, i + 1, s); // четная длина палиндрома
            if (even.size() > ans.size()) { // обновляем ответ
                ans = even;
            }
        }

        return ans;
    }
};
