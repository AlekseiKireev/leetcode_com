https://leetcode.com/problems/remove-nth-node-from-end-of-list/

https://walkccc.me/LeetCode/problems/0019/

____

[Разбор задачи 19 leetcode.com Remove Nth Node From End of List. Решение на C++](https://www.youtube.com/watch?v=-Fak6wi8I98)

1. Наивный способ. 

Посчитать длину списка. Если длина == n - возвращаем head->next.

Иначе делаем шаги от head в количестве (len - n - 1) - получаем элемент, предшествующий удаляемому. 
Меняем его next на элемент после удаляемого.

cur->next = cur->next->next

Отдельный вопрос - нужно ли удалять недоступный более по списку элемент из кучи, т.е. воспользоваться delete

2. follow up - за один проход.

Операций будет столько же. Два указателя, идущих по списку с расстоянием n / n+1.

