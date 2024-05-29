https://leetcode.com/problems/minimum-window-substring/description/

https://walkccc.me/LeetCode/problems/76/

У Федора Меньшикова разбор отсут-т!

_____

Делаем анаграмму строки t (CharToCount, для простоты лучше количество делать отрицательным!)

обновляем искомое, если 
* в Substring содержаться ВСЕ символы из t
* Длина текущего Minimum Window Substring меньше длины предыдущего
* сдвиг левого указателя необходим для минимизации искомого
