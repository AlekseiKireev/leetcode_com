class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end()); // изменяем порядок слов
        int n = s.size();
        int left = 0;
        int right = 0;
        
        for (int i = 0; i < n; i++) {

            for (;i < n && s[i] == ' ';i++); // пропускаем все пробелы

            if (i == n) {break;}

            // находим левую и правую границу слову
            while (i < n && s[i] != ' ') { // перезапис-м данные
                s[right++] = s[i++];
            } // right указывает на пробел

            reverse(s.begin() + left, s.begin() + right); // разворачиваем слово
            s[right++] = ' '; // добавляем пробел
            left = right; // left указывает на пробел
            
        }

        //s.resize(right - 1); // необходим, если данные передаются по ссылке
        return s.substr(0,right - 1);
    }
};
