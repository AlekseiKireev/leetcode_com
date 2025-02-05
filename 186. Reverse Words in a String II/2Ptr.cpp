class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        
        // Разворачиваем весь массив
        reverse(s.begin(), s.end());

        for (int right = 0; right < n; ++right) {

            if (s[right] != ' ') {
                // Определяем границы слова
                int left = right;
                for (;right < n && s[right] != ' '; ++right);

                // Разворачиваем текущее слово
                reverse(s.begin() + left, s.begin() + right);
            }
        }
    }
};
