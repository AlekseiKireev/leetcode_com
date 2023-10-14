https://leetcode.com/problems/odd-even-linked-list/description/

https://walkccc.me/LeetCode/problems/0328/

https://github.com/doocs/leetcode/tree/main/solution/0300-0399/0328.Odd%20Even%20Linked%20List

___________

[Разбор задачи 328 leetcode.com Odd Even Linked List. Решение на C++](https://www.youtube.com/watch?v=dfPskeCkSXg)

1. Очевидный способ -
- пройти по исходному списку, формируя два
- подцепить второй к концу первого

Реализовать очередь - добавление в конец списка должно быть 0(1).

2. Чуть менее очевидный
- пройти по исходному списку, переставляя указатели next.
- подцепить второй список к концу первого. Отслеживать, какой последний посещённый элемент из первого списка.

а->b->с

а->next = а->next->next
