[Разбор задачи 523 leetcode.com Continuous Subarray Sum. Решение на C++](https://www.youtube.com/watch?v=q7tOK0JsHWo&ab_channel=3.5%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B8%D0%B2%D0%BD%D0%B5%D0%B4%D0%B5%D0%BB%D1%8E)

1. Наивный алгоритм.

Перебираем позицию начала подмассива, позицию конца подмассива, идём по подмассиву, суммируем. 
3а одну операцию (% k) проверяем, что сумма кратна k. k == 0 - отдельное условие, что сумма подмассива О. 
Подмассив длины хотя бы 2 - позиции конца перебираем от позиции начала +1.

n - длина массива

0(n^3) по времени  -- n раз перебираем начало -- l, n раз перебираем конец -- r, перебираем [l, r] -- в худшем случае n раз  
0(1) по памяти

10.000^3 = 10^12.
3а 1 секунду успеваем 10^8.

Гарантирован ответ Time limit ехсеедед.

2. Ускоряем до 0(n^2)

будем находить сумму одновременно с движением позиции конца 
подмассива.

<!--
   2 3 5 7
   ^
   flrst
       ^
      lаst
-->

|     2    	|     3    	| 5 	| 7 	| nums 	|
|:--------:	|:--------:	|---	|---	|------	|
| ^ <br> f 	| ^ <br> l 	|   	|   	|      	|

|     2    	|     3    	| 5 	| 7 	| nums 	|
|:--------:	|:--------:	|---	|---	|------	|
| ^ <br> f 	| 	|  ^ <br> l 	|    	|      	|

Двинули lаst - к сумме предыдущего отрезка добавилось только последнее число.

0(n^2) по времени  
0(1) по памяти

__________________________

To understand this question, you have to understand how remainders work. If k = 5, then 6 % 5 = 1, which also means (6 + 5) % 5 = 1.  
So you use a hash map to check if you have seen that remainder before. If yes, then you know between both indexes, it is 5 (i.e. (6 + 5) - 6 = 5).  
This question tests nothing other than knowing how remainders work.

This helped me visualize the ans. In the example:
[23,2,6,4,7] k =12

(23)%12 = 11  
(23+2)%12=1  
(23+2+6)%12 = 7  
(23+2+6+4)%12=11 -> seen before, so return true because:

(23+2+6+4) - (23) = 12 -> 12 % 12 = 0
