https://leetcode.com/problems/candy/description/

https://walkccc.me/LeetCode/problems/135/

У Федора Меньшикова разбор отсут-т!

    ratings = [1,2,3,4,5] 
    Output 15
___

для обоих подходов характерно следующая идея: $ratings[i-l] < ... < ratings[i-1] < ratings[i] > ... > ratings[i+r]$ --> candy[i] = max(l,r) + 1 -- это хорошо видно из графика, "+1" следует из "Each child must have at least one candy." --> надо обрабатывать пики, т.е. фрагменты вида

              /\
             /  \
            /    \
           /      \
                   \

Иначе будет ошибка, ели обрабатывать впадины:

                      max2
            max1       /
               \      /
                \    /
                 \  /
                  \/

# O(1)

Ввиду предыдущего замечания можнно понять, что порядок циклов при подсчете следующий: сначала проход на возрастание, затем на убывание. Что примечательно, для решения за O(n) по памяти таких требований нет. Если попробовать считать не пик а впадину, будет вычитаться два локальных максимума, что ошибочно

```objectives
We can consider this problem like valley and peak problem. In each valley there should be 1 candy and for each increasing solpe in either side we need to increse candy by 1. Peaks have highest candy. If any equal rating is found then candy resets to 1 as two equal neighbours may have any number of candies. The peak should contain the higher number of candy between which is calculated from the incresing slope and which is calculated from decreasing slope. Because this will satisfy the condition that peak element is having more candies than its neighbours.

Example :

Let take the Rating as : [1,3,6,8,9,5,3,6,8,5,4,2,2,3,7,7,9,8,6,6,6,4,2]

Each child represented as rating(candy he is given)
Peak = max(peak, valley)

See when peak is encountered we take max of the peak calculated from left and valley calculated from right.
When we get any equal element it gets reset to 1 candy or if it is peak we take max(0, right valley)

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
Implementation :

So we take initially n candy for n children. Then we start traversing the rating array from the second element. If we find equal elements we continue to next element as they already have 1 candy.

If an increasing slop is found (ratings[i] > ratings [i-1]) we increase value of peak and and add the peak value to candy. After each iteration new peak is found and the value is added to candy. In this way we also get the value of minimum height of the peak at the end.

If a decreasing slope is found (ratings[i] < ratings [i-1]) we calculate the depth of the valley which is in turn the minimum height of the previous peak. In each iteration we increse the valley by 1 and add it to the candy. You can visualise it as 1 candy is added to each of the previous members untill peak or the new peak value is interted at the previous peak and other values are shifted to right by 1 place. We also need to check if it is going out of array if so then return the number of candy.

After this we can see we have added the peak value twice in candy once as peak and once as valley. But we need only the max value out of these two so we substract the min(peak, valley) from candy.

After that return the candy.

Note : We have considered the sequence increasing -> decreasing as peak should have the max value between the height of left (increasing) side and height of right (decreasing) side. In case of decresing -> increasing we dont need to give special attention as the vallley will always have 1 candy and in our code in this case peak will have 0 value so nothing will be substracted from the candy in the end of iteration.
```

# O(n)

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
