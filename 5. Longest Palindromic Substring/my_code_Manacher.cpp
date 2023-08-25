// https://ru.wikipedia.org/wiki/%D0%9F%D0%BE%D0%B8%D1%81%D0%BA_%D0%B4%D0%BB%D0%B8%D0%BD%D0%BD%D0%B5%D0%B9%D1%88%D0%B5%D0%B9_%D0%BF%D0%BE%D0%B4%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B8-%D0%BF%D0%B0%D0%BB%D0%B8%D0%BD%D0%B4%D1%80%D0%BE%D0%BC%D0%B0#%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%9C%D0%B0%D0%BD%D0%B0%D0%BA%D0%B5%D1%80%D0%B0
class Solution {
public:
    string longestPalindrome(string s) {

        vector<char> s2(s.size() * 2 + 1, '#');
        //создаем псевдостроку с границами в виде символа '#'
        for(int i = 0; i != s.size(); ++i){
            s2[i*2 + 1] = s[i];
        }

        int p[s2.size()];
        int r, c, index, i_mir;
        int maxLen = 1;
        i_mir = index = r = c = 0;

        for(int i = 1; i != s2.size() - 1; ++i){
            i_mir = 2*c-i;

            //Если мы попадаем в пределы радиуса прошлого результата,
            //то начальное значение текущего радиуса можно взять из зеркального результата
            p[i] = r > i ? min(p[i_mir], r-i) : 0;

            while(i > p[i] && (i + p[i] + 1) < s2.size() && s2[i - p[i] - 1] == s2[i + p[i] + 1])
                ++p[i];

            if(p[i] + i > r){
                c = i;
                r = i + p[i];
            }

            if(maxLen < p[i]){
                maxLen = p[i];
                index = i;
            }
        }

        //Отображаем найденные позиции на оригинальную строку
        return s.substr((index-maxLen)/2, maxLen);
        
    }
};
