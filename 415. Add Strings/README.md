https://leetcode.com/problems/add-strings/description/

https://en.cppreference.com/w/cpp/string/basic_string/stol

https://e-maxx.ru/algo/big_integer

Алгоритм: 
* инициализируем указатели F и S так, чтобы они указывали на младшие разряды  
* Входим в цикл, до тех пор, пока F действительна ИЛИ S действительна ИЛИ carry != 0  
** получаем значения, на которые указывают F и S  
** кладем целую часть в текущий разряд  
** обновляем carry  
** сдвигаем указатель  
________

https://www.geeksforgeeks.org/converting-strings-numbers-c-cpp/

ПО СУТИ В ЗАДАЧЕ ПРОСЯТ СДЕЛАТЬ КАЛЬКУЛЯТОР ДЛЯ ЦЕЛОЧИСЛЕННЫХ ТИПОВ ЗА ПРЕДЕЛАМИ ТИПОВ ДАННЫХ В C++

[Разбор задачи 415 leetcode.com Add Strings. Решение на C++](https://www.youtube.com/watch?v=yorX7I4wNaA)

________

Аналог: 

[2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

https://github.com/SkosMartren/leetcode_com/tree/main/2.%20Add%20Two%20Numbers
________

На основе примера:

|   	| 9 	| 9 	| 9 	|
|---	|---	|---	|:-:	|
| + 	|   	|   	|   	|
|   	|   	|   	| 2 	|
| - 	| - 	| - 	| - 	|
| 1 	| 0 	| 0 	| 1 	|

Можно легко прочувствовать логическое условие "i1 >= 0 || i2 >= 0 || carry > 0"
