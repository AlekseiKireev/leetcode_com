https://leetcode.com/problems/multiply-strings/

https://e-maxx.ru/algo/big_integer

У Федора Меньшикова разбор отсут-т!

_____

Заметим, что:

$$num1 =\pm \sum_{k=0}^{{m-1}}a_{k}10^{k} : 0 <= a_{k} <= 9$$

$$num2 =\pm \sum_{k=0}^{{n-1}}b_{k}10^{k} : 0 <= b_{k} <= 9$$

тогда $num1 * num2 = a_{m-1} \cdot b_{n-1} \cdot 10^{m-1} \cdot 10^{n-1} + \ldots = a_{m-1} \cdot b_{n-1} \cdot 10^{m + n - 2} + \ldots$ откуда следует, что максимальное количество разрядов в ответе равно 
при $a_{m-1} \cdot b_{n-1} > 9$, т.е. старший разряд будет равен $(m + n - 2) + 1 = m + n - 1$ [+ 1 ввиду того, что вынесли 10 из $a_{m-1} \cdot b_{n-1}$], тогда $MaxSizeProduct = (m + n - 1) + 1 = m + n$ -- данные рассуждения можно прочустоввать на примере: $999 \cdot 999 = ( 9 \cdot 10^{2}  + 9 \cdot 10^{1} + 9 \cdot 10^{0}) \cdot (9 \cdot 10^{2}  + 9 \cdot 10^{1} + 9 \cdot 10^{0})$


_____

на основе рисунка

<img src="https://github.com/SkosMartren/useful-materials/blob/main/for_43_leetcode_1.png" width="300" height="300"/>

можно понять CurrentPosition и причину использования reverse

   11
x  18
-----
   88  (11 * 8)
+ 110  (11 * 10, shifted one position to the left)
-----
  198

_____

Отметим, что $25 \cdot 3 = 75$, при этом $MaxSizeProduct = 3$, т.е. $answer = 570$ -- при использовании $ranges::reverse(answer)$ получим $075$ -- то есть в наличии будут ведущие нули, что недопустимо, поэтому надо проверить старший разряд: 

        if (answer.back() == '0') {
            answer.pop_back();
        }
