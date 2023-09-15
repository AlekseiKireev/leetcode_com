https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

https://walkccc.me/LeetCode/problems/0034/

__________________

[Разбор задачи 34 leetcode.com Find First and Last Position of Element in Sorted Array. Решение C++](https://www.youtube.com/watch?v=tnLSdiQW-_c)

1. Использовать библиотеки С++. 

<algorithm>

lower_bound - возвращает итератор на первый элемент >= искомому  
upper_bound - возвращает итератор на первый элемент > искомого

Итератор переводим в индекс. Для lower_bound проверяем, что элемент на этой позиции - искомый, для upper_bound из индекса вычитаем 1.

2. Двоичный поиск вручную

Поиск 1: левая граница.

left - позиция элемента < target  
right - позиция элемента >= target

Сужаем интервал до 1е- + 1 == right. Если элемент есть - то он в позиции rlght.

Поиск 2: правая граница.

left - позиция элемента <= target  
right - позиция элемента > target

Сужаем интервал до 1е + 1 == right. Если элемент есть в массиве - то эти элементы заканчиваются в left.



__________________
