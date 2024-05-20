https://leetcode.com/problems/candy/description/

https://walkccc.me/LeetCode/problems/135/

У Федора Меньшикова разбор отсут-т!

___

```objectives

We can easily calculate the number of candy needed by using an array to store the candy of each child. And after that traverse the rating array twice. 
* The first loop makes sure children with a higher rating get more candy than its left neighbor, 
* the second loop makes sure children with a higher rating get more candy than its right neighbor. 

At last add the total number of candies. This approach is O(n) time and O(n) space.


Мы можем легко рассчитать необходимое количество конфет, используя массив для хранения конфет каждого ребенка. И после этого дважды пройдемся по массиву оценок. 
* В первом цикле дети с более высоким рейтингом получают больше конфет, чем их сосед слева, 
* во втором цикле дети с более высоким рейтингом получают больше конфет, чем их соседи справа. 

Наконец, подсчитайте общее количество конфет. Этот подход требует O (n) времени и O (n) пространства.

ratings    = [1,3,6,8,9,5,3,6,8,5,4,2,2]


           (5)         (4)                         (3)
            9           8                           9
           /|\         /|\                         /|\
          / | \       / | \                (3)    / | \
      (4)8  |  5(2)  6  |  5(3)             7 __ 7  |  8(2)
        /   |   \   (2) |   \              /|   (1) |   \
       /    |    \ /    |    \            / |    |  |    \         (3)
   (3)6     |     3     |     4(2)       3(2)    |  |     6 __ 6 __ 6    -> Total candy = 50
     /      |    (1)    |      \        /   | Reset |    (1)  (1)   |\
    /       |           |       \      /    |  to 1 |          |    | \
(2)3        |           |        2 __ 2     |       |          |    |  4(2)
  /         |           |       (1)  (1)    |       |        Reset  |   \
 /          |           |                   |       |         to 1  |    \
1(1)        |           |                   |       |               |     2(1)
   Peak= max(5,3)  Peak= max(3,4)    Peak= max(3,0) |         Peak= max(0,3)
                                               Peak= max(2,3)   




ratings    : 1 3 6 8 9 5 3 6 8 5 4 2 2 
leftToRight: 1 2 3 4 5 1 1 2 3 1 1 1 1 
rightToLeft: 1 1 1 1 3 2 1 1 4 3 2 1 1 

на основе 9(5) можно заметить необходимость максимизации для прохода слева направа
на основе 8(4) можно заметить необходимость максимизации для прохода справа налево
```
