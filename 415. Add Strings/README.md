https://leetcode.com/problems/add-strings/description/

https://en.cppreference.com/w/cpp/string/basic_string/stol

https://www.geeksforgeeks.org/converting-strings-numbers-c-cpp/

ПО СУТИ В ЗАДАЧЕ ПРОСЯТ СДЕЛАТЬ КАЛЬКУЛЯТОР ДЛЯ ЦЕЛОЧИСЛЕННЫХ ТИПОВ ЗА ПРЕДЕЛАМИ ТИПОВ ДАННЫХ В C++

[Разбор задачи 415 leetcode.com Add Strings. Решение на C++](https://www.youtube.com/watch?v=yorX7I4wNaA)

Можно ли использовать string_view и велика ли будет разница?

Аналог: [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

________

На основе примера:

|   	| 9 	| 9 	| 9 	|
|---	|---	|---	|:-:	|
| + 	|   	|   	|   	|
|   	|   	|   	| 2 	|
| - 	| - 	| - 	| - 	|
| 1 	| 0 	| 0 	| 1 	|

Можно легко прочувствовать логическое условие "i1 >= 0 || i2 >= 0 || carry > 0"
