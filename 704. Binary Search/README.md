https://leetcode.com/problems/binary-search/description/

[Разбор задачи 704 leetcode.com Binary Search. Решение на C++](https://www.youtube.com/watch?v=VL30zBhwjMQ)

Аналог: https://contest.yandex.ru/contest/27844/problems/A/

[АиСД S01E05. Двоичный поиск](https://www.youtube.com/watch?v=9Wjzf8KKvYQ&ab_channel=PavelMavrin) - примечательны первые 20 минут

upper_bound.cpp - upper_bound

704a.cpp - lower_bound

704b.cpp - демонстрация неудачного [работающего] двоичного поиска и мотивировка к 704c.cpp 

704c.cpp - это читабельнее 704b.cpp и ближе к lower_bound по реализации. Рекомендовал как Маврин, так и Фёдор Владимирович

_______________


target = 3

| void 	| nums.begin() 	| nums.end() 	|     nums_it 	|
|------	|---	|------------	|:-----------:	|
|     	| 5 	|            	|     nums    	|
|      	|  ^	|           	| upper_bound 	|
|      	|  ^ 	|            	| lower_bound 	|


target = 5

| void 	| nums.begin() 	| nums.end() 	|     nums_it 	|
|------	|---	|------------	|:-----------:	|
|     	| 5 	|   	        |     nums    	|
|      	|   	|      ^     	| upper_bound 	|
|      	| ^ 	|            	| lower_bound 	|


target = 7

| void 	| nums.begin() 	| nums.end() 	|     nums_it 	|
|------	|---	|------------	|:-----------:	|
|   	  | 5 	|     	      |      nums   	|
|      	|   	|      ^     	| upper_bound 	|
|      	|  	  |      ^    	| lower_bound 	|


На основе примеров можно утвнрждать, что если существует auto ItCheck = prev(ranges::upper_bound(nums, target)), то надо проверить на истиность *ItCheck == target -- если истино, возвращаем индекс, иначе возвращаем -1.  
Потенциальная проблема -- ranges::upper_bound(nums, target) = nums.begin()  --> на ItCheck словим исключение out of range. Чтобы этого ибежать, перейдем к индексам сразу: 
 const int idx = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1; -- где "- 1" выполняет операцию, аналогичную prev

_______________

Бинарный поиск ищет ** *первый* ** индекс для которого выполняется инвариант 
