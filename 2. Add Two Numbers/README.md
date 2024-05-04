

Почему  
в конце beforeRes.next -- вызывается по умолчанию при написании ListNode beforeRes;  
во всех решениях два контейнера -- один контейнер указывет на свой конец, второй на ведущий ноль   


https://leetcode.com/problems/add-two-numbers/

- https://leetcode.com/problems/add-two-numbers/solutions/1340/a-summary-about-how-to-solve-linked-list-problem-c/

________

https://e-maxx.ru/algo/big_integer

        // /assert(nullptr == false);/ error!!
        assert(!nullptr);
        
________

https://walkccc.me/LeetCode/problems/0002/

[Разбор задачи 2 leetcode.com Add Two Numbers. Решение на C++](https://www.youtube.com/watch?v=QflftNTHeeE)

Сложение идет от младших разярдов к старшему, узнать какая сторона считается за младший разряд!

________

Аналог: [415. Add Strings](https://leetcode.com/problems/add-strings/description/)

https://github.com/SkosMartren/leetcode_com/tree/main/415.%20Add%20Strings


________

На основе примера:

|   	| 9 	| 9 	| 9 	|   	|
|---	|---	|---	|---	|:-:	|
| + 	|   	|   	|   	|   	|
|   	| 2  	|   	|  	|   	|
| - 	| - 	| - 	| - 	| - 	|
|  	| 1 	| 0 	| 0 	|  1 	|

Можно легко прочувствовать логическое условие "carry != 0 || l1 != nullptr || l2 != nullptr"

____

Лакман Макдауэл - Карьера программиста (2020)

условие: страница 87, задача 2.5.

решение: страница 220

