https://leetcode.com/problems/lru-cache/

https://walkccc.me/LeetCode/problems/0146/

____

[Разбор задачи 146 leetcode.com LRU Cache. Решение на C++](https://www.youtube.com/watch?v=KptTnhWtBZY)

get O(1) - хэш-таблица. unordered_map

put O(1) - двусвязный список.

- O(1) удаление любого элемента, O(1) добавление в конец.

unordered_тар<key, value> - получаем, что возвращать на get и что записывать в put

unordered_тар<key, std::list<key>::iterator>

O(1) == average O(1)

___

https://stackoverflow.com/questions/2504178/lru-cache-design

https://www.geeksforgeeks.org/lru-cache-implementation/

https://habr.com/ru/articles/136758/

https://blog.skillfactory.ru/glossary/lru/

https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D1%8B_%D0%BA%D1%8D%D1%88%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F

