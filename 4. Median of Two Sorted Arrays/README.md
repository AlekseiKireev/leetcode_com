https://leetcode.com/problems/median-of-two-sorted-arrays/description/

Аналог: (????)  
https://contest.yandex.ru/contest/27844/problems/J/  
https://contest.yandex.ru/contest/27844/problems/K/  

https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/

У Федора Меньшикова разбор отсут-т!

Добавить в конец большого вектора малый + воспользоваться nth_element?

___________

related: https://github.com/SkosMartren/leetcode_com/tree/main/88.%20Merge%20Sorted%20Array

___

нечетная длина merge(x,y)

x  $\to \quad \quad$  $x_1  \quad  x_2 \quad | \quad x_3 \quad x_4 \quad x_5$  <br>
y  $\to \quad \quad$  $y_1  \quad y_2 \quad y_3 \quad y_4 \quad y_5 \quad | \quad y_6  \quad y_7 \quad y_8$ 

default:
- $... \leqslant x_2 \leqslant x_3 \leqslant ...$
- $... \leqslant y_5 \leqslant y_6 \leqslant ...$

* if $x_2 \leqslant y_6$ -->  $\quad x_1 \leqslant x_2 \leqslant y_6$
* if $y_5 \leqslant x_3$ -->  $\quad y_1 \leqslant ... \leqslant y_5 \leqslant x_3$

Тогда, если упорядочить $x_1  \quad  x_2 \quad y_1  \quad y_2 \quad y_3 \quad y_4 \quad y_5$, то справа будет либо $y_5$ либо $x_2$

$median = max(x_2, y_5)$

четная длина merge(x,y)

x  $\to \quad \quad$  $x_1  \quad  x_2 \quad | \quad x_3 \quad x_4 \quad x_5 \quad x_6$ <br>
y  $\to \quad \quad$  $y_1  \quad y_2 \quad y_3 \quad y_4 \quad y_5 \quad | \quad y_6  \quad y_7 \quad y_8$ 

$median = [max(x_2, y_5) + min(x_3, y_6) ] / 2$

my ex 1

            [1,2]
            [3,4,5]

Expected 3.00000

my ex 2

            [1,3]
            [2,4,5]

Expected 3.00000

my ex 3

            [1,2,6,11]
            [3,4,5]

Expected 4.00000
