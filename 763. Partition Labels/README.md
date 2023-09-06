56. Merge Intervals == https://leetcode.com/problems/merge-intervals/ -- аналог. Используется в решении merge_Intervals_upd.cpp

Доказательство невыгодности использования unordered_map: https://github.com/SkosMartren/leetcode_com/tree/main/350.%20Intersection%20of%20Two%20Arrays%20II

https://leetcode.com/problems/partition-labels/

https://walkccc.me/LeetCode/problems/0763/

https://leetcode.com/problems/partition-labels/solutions/899214/2-solutions-explanation-picture/

https://leetcode.com/problems/partition-labels/solutions/1868842/java-c-visually-explaineddddd/

https://leetcode.com/problems/partition-labels/solutions/601546/c-solution-with-detailed-explanation-o-n-time-complexity/

https://leetcode.com/problems/partition-labels/editorial/

У Федора Меньшикова разбор отсут-т!

___

<p align="center"> Example 1: </p>

<img src="https://github.com/SkosMartren/useful-materials/blob/main/for_763_leetcode_1.png" width="1500" height="400"/>  
Демонстарция аналога с 56. Merge Intervals

<p align="center"> My Example 1: </p>

Input: s = "abcdefg"  
Output: 1 1 1 1 1 1 1  
Explanation:  
"We want to partition the string into as many parts as possible so that each letter appears in at most one part."  

<p align="center">  part Example 1: </p>

|           idx           |   | d | e | f | g |  h |  i |  j |  k |  l |
|:-----------------------:|:-:|:-:|:-:|:-:|:-:|:--:|:--:|:--:|:--:|:--:|
| CharToEndIdx[idx - 'a'] |   | 5 | 6 | 2 | 4 | 10 | 13 | 14 | 11 | 12 |

IdxEndPart будет обновлятся через CharToEndIdx

| i   	|   	|            -1           	|          0          	| 1 	| 2 	| 3 	| 4 	| 5 	| 6 	| 7 	| 8 	| 9 	| 10 	| 11 	| 12 	| 13 	| 14 	|
|:---:	|:-:	|:-----------------------:	|:-------------------:	|:-:	|:-:	|:-:	|:-:	|:-:	|:-:	|:-:	|:-:	|:-:	|:--:	|:--:	|:--:	|:--:	|:--:	|
|  s[i] |   	|                         	|          d          	| e 	| f 	| e 	| g 	| d 	| e 	| h 	| i 	| j 	|  h 	|  k 	|  l 	|  i 	|  j 	|
| ptr 	|   	| ^^^ <br> PrevIdxEndPart 	| ^^^ <br> IdxEndPart 	|   	|   	|   	|   	|   	|   	|   	|   	|   	|    	|    	|    	|    	|    	|


<p align="center"> i = 0 </p>

|   idx  	|   	|            -1           	|      0     	| 1 	| 2 	| 3 	| 4 	|          5          	| 6 	| 7 	| 8 	| 9 	| 10 	| 11 	| 12 	| 13 	| 14 	|
|:------:	|:-:	|:-----------------------:	|:----------:	|:-:	|:-:	|:-:	|:-:	|:-------------------:	|:-:	|:-:	|:-:	|:-:	|:--:	|:--:	|:--:	|:--:	|:--:	|
| s[idx] 	|   	|                         	|      d     	| e 	| f 	| e 	| g 	|          d          	| e 	| h 	| i 	| j 	|  h 	|  k 	|  l 	|  i 	|  j 	|
|   ptr  	|   	| ^^^ <br> PrevIdxEndPart 	| ^^^ <br> i 	|   	|   	|   	|   	| ^^^ <br> IdxEndPart 	|   	|   	|   	|   	|    	|    	|    	|    	|    	|

<p align="center"> i = 1 </p>

|   idx  	|   	|            -1           	| 0 	|      1     	| 2 	| 3 	| 4 	| 5 	|          6          	| 7 	| 8 	| 9 	| 10 	| 11 	| 12 	| 13 	| 14 	|
|:------:	|:-:	|:-----------------------:	|:-:	|:----------:	|:-:	|:-:	|:-:	|:-:	|:-------------------:	|:-:	|:-:	|:-:	|:--:	|:--:	|:--:	|:--:	|:--:	|
| s[idx] 	|   	|                         	| d 	|      e     	| f 	| e 	| g 	| d 	|          e          	| h 	| i 	| j 	|  h 	|  k 	|  l 	|  i 	|  j 	|
|   ptr  	|   	| ^^^ <br> PrevIdxEndPart 	|   	| ^^^ <br> i 	|   	|   	|   	|   	| ^^^ <br> IdxEndPart 	|   	|   	|   	|    	|    	|    	|    	|    	|

<p align="center"> ... </p>

<p align="center"> i = 6 </p>

|   idx  	|   	| -1 	| 0 	| 1 	| 2 	| 3 	| 4 	| 5 	|                        6                       	| 7 	| 8 	| 9 	| 10 	| 11 	| 12 	| 13 	| 14 	|
|:------:	|:-:	|:--:	|:-:	|:-:	|:-:	|:-:	|:-:	|:-:	|:----------------------------------------------:	|:-:	|:-:	|:-:	|:--:	|:--:	|:--:	|:--:	|:--:	|
| s[idx] 	|   	|    	| d 	| e 	| f 	| e 	| g 	| d 	|                        e                       	| h 	| i 	| j 	|  h 	|  k 	|  l 	|  i 	|  j 	|
|   ptr  	|   	|    	|   	|   	|   	|   	|   	|   	| ^^^ <br> IdxEndPart <br> i <br> PrevIdxEndPart 	|   	|   	|   	|    	|    	|    	|    	|    	|

Прежде чем PrevIdxEndPart будет указывть на 6, в SizeParts заносится IdxEndPart - PrevIdxEndPart

<p align="center"> i = 7 </p>

|   idx  |   | -1 | 0 | 1 | 2 | 3 | 4 | 5 |            6            |      7     | 8 | 9 |          10         | 11 | 12 | 13 | 14 |
|:------:|:-:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-----------------------:|:----------:|:-:|:-:|:-------------------:|:--:|:--:|:--:|:--:|
| s[idx] |   |    | d | e | f | e | g | d |            e            |      h     | i | j |          h          |  k |  l |  i |  j |
|   ptr  |   |    |   |   |   |   |   |   | ^^^ <br> PrevIdxEndPart | ^^^ <br> i |   |   | ^^^ <br> IdxEndPart |    |    |    |    |


<p align="center"> i = 8 </p>

|     idx    |   | -1 | 0 | 1 | 2 | 3 | 4 | 5 |             6            | 7 |      8     | 9 | 10 | 11 | 12 |          13         | 14 |
|:----------:|:-:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:------------------------:|:-:|:----------:|:-:|:--:|:--:|:--:|:-------------------:|:--:|
|   s[idx]   |   |    | d | e | f | e | g | d |             e            | h |      i     | j |  h |  k |  l |          i          |  j |
|     ptr    |   |    |   |   |   |   |   |   | ^^^  <br> PrevIdxEndPart |   | ^^^ <br> i |   |    |    |    | ^^^ <br> IdxEndPart |    |

<p align="center"> i = 9 </p>

|   idx  |   | -1 | 0 | 1 | 2 | 3 | 4 | 5 |            6            | 7 | 8 |      9     | 10 | 11 | 12 | 13 |          14         |
|:------:|:-:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-----------------------:|:-:|:-:|:----------:|:--:|:--:|:--:|:--:|:-------------------:|
| s[idx] |   |    | d | e | f | e | g | d |            e            | h | i |      j     |  h |  k |  l |  i |          j          |
|   ptr  |   |    |   |   |   |   |   |   | ^^^ <br> PrevIdxEndPart |   |   | ^^^ <br> i |    |    |    |    | ^^^ <br> IdxEndPart |

<p align="center"> ... </p>

<p align="center"> i = 14 </p>

|   idx  |   | -1 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 |                        14                       |
|:------:|:-:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:--:|:--:|:--:|:--:|:-----------------------------------------------:|
| s[idx] |   |    | d | e | f | e | g | d | e | h | i | j |  h |  k |  l |  i |                        j                        |
|   ptr  |   |    |   |   |   |   |   |   |   |   |   |   |    |    |    |    | ^^^ <br> IdxEndPart <br> i <br> PrevIdxEndPart  |

Прежде чем PrevIdxEndPart будет указывть на 14, в SizeParts заносится IdxEndPart - PrevIdxEndPart
