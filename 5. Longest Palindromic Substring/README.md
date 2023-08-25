https://leetcode.com/problems/longest-palindromic-substring/

https://walkccc.me/LeetCode/problems/0005/

У Федора Меньшикова разбор отсут-т!

<p align="center"> Manacher's algorithm | Алгоритм Манакера </p>

https://ru.wikipedia.org/wiki/%D0%9F%D0%BE%D0%B8%D1%81%D0%BA_%D0%B4%D0%BB%D0%B8%D0%BD%D0%BD%D0%B5%D0%B9%D1%88%D0%B5%D0%B9_%D0%BF%D0%BE%D0%B4%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B8-%D0%BF%D0%B0%D0%BB%D0%B8%D0%BD%D0%B4%D1%80%D0%BE%D0%BC%D0%B0#%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%9C%D0%B0%D0%BD%D0%B0%D0%BA%D0%B5%D1%80%D0%B0 == code on C++

https://en.wikipedia.org/wiki/Longest_palindromic_substring#Manacher's_algorithm

https://neerc.ifmo.ru/wiki/index.php?title=%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%9C%D0%B0%D0%BD%D0%B0%D0%BA%D0%B5%D1%80%D0%B0

https://neerc.ifmo.ru/wiki/index.php?title=%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0_%D0%BE_%D0%BD%D0%B0%D0%B8%D0%B1%D0%BE%D0%BB%D1%8C%D1%88%D0%B5%D0%B9_%D0%BF%D0%BE%D0%B4%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8-%D0%BF%D0%B0%D0%BB%D0%B8%D0%BD%D0%B4%D1%80%D0%BE%D0%BC%D0%B5

https://e-maxx.ru/algo/palindromes_count

https://www.techiedelight.com/longest-palindromic-substring-non-dp-space-optimized-solution/

https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-4/

<p align="center"> DP </p>

_____

Утверждение:  

DP[i][j] = true <--> строка {s[i], s[i + 1], ..., s[j - 1], s[j]} является палиндромом. Это может быть только в случае выполнения условие DP[i+1][j-1] = true (палиндром) AND s[i] == s[j] == true (прибавив к концам палиндрома одинаковые символы получим палиндром) --> assert(i <= j)  

DP[i][i] = true <--> строка {s[i]} -- один символ удовлетворяют опредлению палиндрома. Учтем, что 0 <= i <= s.size() - 1

Ввиду определения DP[i][j] можно утверждать, что DP имеет смысл только при i <= j --> assert(i <= j)

*Положение DP[i+1][j-1] можно увидеть по таблице:*

| **_DP_** 	| 0 	| 1 	|  2  	| ... 	| j - 2 	|       j - 1      	|      j     	| ... 	| n - 1 	|
|:--------:	|:-:	|:-:	|:---:	|:---:	|:-----:	|:----------------:	|:----------:	|-----	|-------	|
|     0    	| 1 	|   	|     	|     	|       	|                  	|            	|     	|       	|
|     1    	|   	| 1 	|     	|     	|       	|                  	|            	|     	|       	|
|    ...   	|   	|   	| ... 	|     	|       	|                  	|            	|     	|       	|
| i        	|   	|   	|     	| ... 	|       	|                  	| We're here 	|     	|       	|
| i+1      	|   	|   	|     	|     	| 1     	| We need to check 	|            	|     	|       	|
| i+2      	|   	|   	|     	|     	|       	| 1                	|            	|     	|       	|
| ...      	|   	|   	|     	|     	|       	|                  	| 1          	|     	|       	|
| n - 2    	|   	|   	|     	|     	|       	|                  	|            	| 1   	|       	|
| n - 1    	|   	|   	|     	|     	|       	|                  	|            	|     	| 1     	|

Ввиду всего вышесказанного рассмотрим пример при n = 4

| **_DP_** 	|   0  	|            1            	|      2     	| 3 	|
|:--------:	|:----:	|:-----------------------:	|:----------:	|:-:	|
|     0    	|   1  	|                         	|            	|   	|
|     1    	| NULL 	|            1            	| We're here 	|   	|
|     2    	| NULL 	| NULL / We need to check 	|      1     	|   	|
| 3        	| NULL 	| NULL                    	| NULL       	| 1 	|

и увидем необходимость препроцессинга вплоть до n - 1 не только главной диагонали, но и первой диагонали, стоящий над главной
