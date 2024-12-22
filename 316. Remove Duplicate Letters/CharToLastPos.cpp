class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> CharToLastPos(256, -1); // если кодировка не известна, то u_m<char, int>
        for (int i = 0; i < s.size(); ++i) {
            CharToLastPos[s[i]] = i; // Запоминаем правую позицию каждого символа
        }

        /*Для гарантии выполнения "every letter appears once and only once" */
        vector<bool> taked(256, false);

        string Ans;

        for (int i = 0; i < s.size(); ++i) {
            if (taked[s[i]]) {
                continue; // Пропускаем символы, которые уже добавлены в результат
            }

            while (
                !Ans.empty() /*нельзя удалять из пустой сроки*/
                &&  Ans.back() > s[i] /*строку можно сделать более "smallest in lexicographical order" */
                &&  CharToLastPos[Ans.back()] > i /*для этого есть возможность: справа от i существует символ Ans.back()*/
            ) {
                taked[Ans.back()] = false; // Удаляем символ из результата
                Ans.pop_back();
            }

            Ans.push_back(s[i]);
            taked[s[i]] = true; // Помечаем символ как взятый
        }

        return Ans;        
    }
};
