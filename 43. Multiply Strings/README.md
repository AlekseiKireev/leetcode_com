https://e-maxx.ru/algo/big_integer

_____

Заметим, что:

$$num1 =\pm \sum_{k=0}^{{m-1}}a_{k}10^{k}$$

$$num2 =\pm \sum_{k=0}^{{n-1}}b_{k}10^{k}$$

тогда $num1 * num2 = 10^{m-1} \cdot 10^{n-1} + \ldots = 10^{m + n - 2} + \ldots$ откуда следует, что количество разрядов в ответе равно $(m + n - 2) + 1 = m + n = MaxSizeProduct$


_____

на основе рисунка

<img src="https://github.com/SkosMartren/useful-materials/blob/main/for_43_leetcode_1.png" width="300" height="300"/>

можно понять CurrentPosition и причину использования reverse

_____

Отметим, что $25 \cdot 3 = 75$, при этом $MaxSizeProduct = 3$, т.е. $answer = 570$ -- при использовании $ranges::reverse(answer)$ получим $075$ -- то есть в наличии будут ведущие нули, что недопустимо, поэтому надо проверить старший разряд: 

        if (answer.back() == '0') {
            answer.pop_back();
        }
