class Solution {

public:

    bool isIsomorphic(string S, string T) {
        
        const int SIZE = S.size();
        unordered_map<char, char> S_ch_To_T_ch;
        unordered_set<char> UsedCharT; // <-- " Wrong Answer 37 / 44 testcases   Input s = "badc" t = "baba" "
        
        for(int i = 0 ; i < SIZE;++i){

            if(S_ch_To_T_ch[S[i]] == '\0' &&  UsedCharT.count(T[i]) == 0){
                S_ch_To_T_ch[S[i]] = T[i];
                UsedCharT.insert(T[i]);
                }
            
        }

        for(char& ch : S){
            ch = S_ch_To_T_ch[ch];
        }

        return S == T;

    }

};
/*
class Solution {

public:

    bool isIsomorphic(string S, string T) {
        
        const int SIZE = S.size();
        unordered_map<char, char> S_ch_To_T_ch;

        for(int i = 0 ; i < SIZE;++i){
            S_ch_To_T_ch[S[i]] = T[i];
        }

        for(char& ch : S){
            ch = S_ch_To_T_ch[ch];
        }

        return S == T;

    }

};



А Б, [8/30/2023 6:27 PM]
условие: https://leetcode.com/problems/isomorphic-strings/description/

код: https://pastebin.com/ENT70UMa

вопрос: в моем коде ошибка
Wrong Answer 37 / 44 testcases   Input s = "badc" t = "baba"

правильно ли понимаю, что из того, что срока S изоморфна строке T не следует, что строка T изоморфна строке S? Вроде как пример именно об этом, но мне думалось с точностью до наоборот, не очень понимаю, как доказать что из 
S ~> T !—> S <~> T
где 
~>  / <~> == направление изоморфизма
 !—> == не следует

Vladimir Mokeev, [8/30/2023 6:34 PM]
Это свойство симметрично

А Б, [8/30/2023 6:34 PM]
а в чем у меня тогда ошибка?

Vladimir Mokeev, [8/30/2023 6:35 PM]
У тебя в а переходит две разные буквы

А Б, [8/30/2023 6:35 PM]
иииии что?)

Aleksandr Khorev, [8/30/2023 6:35 PM]
Если строку х возможно превратить в у, то верно и обратное

Vladimir Mokeev, [8/30/2023 6:36 PM]
Должно быть биективное отображение символов одной в символы другой

А Б, [8/30/2023 6:36 PM]
вот так и думал, значит, ошибка в ином месте, спасибо! А можно теперь локализовать ошибку?)

Aleksandr Khorev, [8/30/2023 6:36 PM]
Это значит что нельзя превратить badc в baba

А Б, [8/30/2023 6:36 PM]
да, похоже на правду

Aleksandr Khorev, [8/30/2023 6:36 PM]
Те тут символ b из первой строки переходит в 2 разных символа в другой строке

Dmitrii Kochetov, [8/30/2023 6:36 PM]
Если мапинг b->b уже занят, то d->b нельзя

Vladimir Mokeev, [8/30/2023 6:37 PM]
Ты при первом проходе можешь перезаписывать значения

А Б, [8/30/2023 6:37 PM]
да я вот думал о таком, но вот до биекции не додумался, оно очевидно, но что-то строго в голове не укладывается....

А Б, [8/30/2023 6:37 PM]
так, думаю, пока разобрался, пойду еще чутка подумаю

А Б, [8/30/2023 6:43 PM]
а как это контрлировать? У меня из идей — завести еще один unordered_map чтобы чекать отображения, но вот что-то жирно по памяти получится, может, это как-то изящно можно?)
*/
