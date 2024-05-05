my_code_slow.cpp == Brute Force working n^3


______

Задачу нахождения самой длинной палиндромиальной подстроки не следует путать с задачей нахождения самой длинной палиндромиальной подпоследовательности.

https://neerc.ifmo.ru/wiki/index.php?title=%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0_%D0%BE_%D0%BD%D0%B0%D0%B8%D0%B1%D0%BE%D0%BB%D1%8C%D1%88%D0%B5%D0%B9_%D0%BF%D0%BE%D0%B4%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8-%D0%BF%D0%B0%D0%BB%D0%B8%D0%BD%D0%B4%D1%80%D0%BE%D0%BC%D0%B5 == Поиск длиннейшей подпоследовательности-палиндрома

____

https://leetcode.com/problems/longest-palindromic-substring/

https://walkccc.me/LeetCode/problems/0005/

У Федора Меньшикова разбор отсут-т!

____

<p align="center"> Manacher's algorithm | Алгоритм Манакера </p>

"
Note: this algorithm is completely out of scope for coding interviews. Because of this, we will not be talking about the algorithm in detail. This approach has been included for the sake of completeness and for those who are curious about algorithms beyond the scope of interviews.
"

https://ru.wikipedia.org/wiki/%D0%9F%D0%BE%D0%B8%D1%81%D0%BA_%D0%B4%D0%BB%D0%B8%D0%BD%D0%BD%D0%B5%D0%B9%D1%88%D0%B5%D0%B9_%D0%BF%D0%BE%D0%B4%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B8-%D0%BF%D0%B0%D0%BB%D0%B8%D0%BD%D0%B4%D1%80%D0%BE%D0%BC%D0%B0#%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%9C%D0%B0%D0%BD%D0%B0%D0%BA%D0%B5%D1%80%D0%B0 == Поиск длиннейшей подстроки-палиндрома --> code on C++

https://en.wikipedia.org/wiki/Longest_palindromic_substring#Manacher's_algorithm == Поиск длиннейшей подстроки-палиндрома

https://neerc.ifmo.ru/wiki/index.php?title=%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%9C%D0%B0%D0%BD%D0%B0%D0%BA%D0%B5%D1%80%D0%B0

https://e-maxx.ru/algo/palindromes_count

https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-4/

_____

<p align="center"> DP </p>

https://www.techiedelight.com/longest-palindromic-substring-non-dp-space-optimized-solution/

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

и увидем необходимость препроцессинга [вплоть до n - 1 символа] не только главной диагонали, но и первой диагонали, стоящий над главной. То есть DP[i][j] = "We're here" надо перемещать по диагоналям слева-направа / снизу-вверх начиная с гавной диагонали, так как он используется информацию из DP[i+1][j-1] = "We need to check" -- диагональ проходящая через DP[i+1][j-1] уже заполнена и нет смысла беспокоится о потенциальных ошибках -- как увидим, это достаточно удобно, хоть из звучит не тривиально.

_____

первыми двумя циклами бегаем по left_ptr и right_ptr : left_ptr < right_ptr, третьим циклом проверяем {s[left_ptr], ..., s[right_ptr]} на палиндром. 
