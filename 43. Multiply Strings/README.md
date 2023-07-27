Заметим, что:

$$num1 =\pm \sum_{k=0}^{{m-1}}a_{k}10^{k}$$

$$num2 =\pm \sum_{k=0}^{{n-1}}b_{k}10^{k}$$

тогда $num1 * num2 = 10^{m-1} \cdot 10^{n-1} + \ldots = 10^{m + n - 1} + \ldots$ откуда следует, что количество разрядов в ответе равно $(m + n - 1) + 1 = m + n = N$


_____

$\begin{array}{r} 
\times \begin{array}{r} 12345 \\ 6789 \\ \hline \end{array} \\ \begin{array}{r} 1\overset{2}{1}\overset{3}{1}\overset{4}{1}\overset{4}{0}5 \\ \overset{1}{9}\overset{2}{8}\overset{3}{7}\overset{4}{6}0\phantom{0} \\ \overset{1}{8}\overset{2}{6}\overset{3}{4}\overset{3}{1}5\phantom{00} \\ \overset{1}{7}\overset{2}{4}\overset{2}{0}\overset{3}{7}0\phantom{000} \\ \hline \overset{1}{8}\overset{1}{3}\overset{2}{8}\overset{1}{1}\overset{1}{0}205 \end{array} 
\end{array}$
