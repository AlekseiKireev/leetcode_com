https://leetcode.com/problems/subarray-sums-divisible-by-k/description/ 

https://walkccc.me/LeetCode/problems/974/

У Федора Меньшикова разбор отсут-т!

analoge: https://github.com/SkosMartren/leetcode_com/tree/main/523.%20Continuous%20Subarray%20Sum -- решение аналогично этой задаче, с той разностью, что надо суммировать префиксы


|       idx      	|   	| 0 	| 1 	| 2 	| 3 	| 4 	|   	|                 Ans                	|
|:--------------:	|:-:	|:-:	|:-:	|:-:	|:-:	|:-:	|:-:	|:----------------------------------:	|
| PrefixMod[idx] 	|   	| 1 	| 0 	| 0 	| 0 	| 0 	|   	|                  0                 	|
|     nums[0]    	|   	| 1 	|   	| 0  	|   	| 1 	|   	| 0 = prev(Ans) + prev(PrefixMod[4]) 	|
|     nums[1]    	|   	| 1 	|   	| 0  	|   	| 2 	|   	| 1 = prev(Ans) + prev(PrefixMod[4]) 	|
|     nums[2]    	|   	| 1 	|   	| 0 	|   	| 3 	|   	| 3 = prev(Ans) + prev(PrefixMod[4]) 	|
|     nums[3]    	|   	| 1 	|   	| 1 	|   	| 3 	|   	| 3 = prev(Ans) + prev(PrefixMod[2]) 	|
|     nums[4]    	|   	| 1 	|   	| 1 	|   	| 4 	|   	| 6 = prev(Ans) + prev(PrefixMod[4]) 	|
|     nums[5]    	|   	| 2 	|  0 	| 1 	|  0 	| 4 	|   	| 7 = prev(Ans) + prev(PrefixMod[0]) 	|
