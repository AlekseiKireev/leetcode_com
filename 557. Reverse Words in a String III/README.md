https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

https://walkccc.me/LeetCode/problems/0557/

Примечательно то, что при запуске теста

    "Let's    take"

выдается ошибка: Invalid Testcase   The words should be separated by a single space. -- об этом и говорится в условии: All the words in s are separated by a single space.
__________

557c-d.cpp -- явная реализация reverse

my_code_two_ptr.cpp == my_code_in_place.cpp == my_code_two_ptr.cpp

[Разбор задачи 557 leetcode.com Reverse Words in a String III. Решение на C++](https://www.youtube.com/watch?v=1IYt44WYzkM)

Ожидаемые характеристики:

- по времени O(n), n - длина строки.  [Если не посетим все символы - ответ получить не получится. Например, вся строка одно слово.]
- по памяти - можно O(1) in-рlасе.

Нужен интерфейс void reverseWords(string &s) 

С интерфейсом leetcode - O(n) по памяти.

string reverseWords(string &s) { - можно O(1) по памяти,но это хак.

Алгоритм:

идём по строке от начала к концу, помним начало очередного слова, как встречаем пробел или конец строки - меняем порядок символов от начала слова до конца слова.

Обсудить на собеседовании: как делать эту задачу для строк UTF-8.

- 1-й уровень - символы кодируются разным количеством байтов. Байты внутри одного символа нужно оставить в том же порядке.
- 2-й уровень - некоторые символы модифицируют значение предыдущего символа - ё - е + две точки выше.

__________

https://quick-bench.com/q/P0YD_sev09aGUENlE960qAsvq8M
