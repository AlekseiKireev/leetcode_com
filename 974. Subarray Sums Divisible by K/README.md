https://leetcode.com/problems/subarray-sums-divisible-by-k/description/ 

https://walkccc.me/LeetCode/problems/974/

У Федора Меньшикова разбор отсут-т!

analoge: https://github.com/SkosMartren/leetcode_com/tree/main/523.%20Continuous%20Subarray%20Sum -- решение аналогично этой задаче, с той разностью, что надо суммировать префиксы

    |       idx      	|   	| 0 	| 1 	| 2 	| 3 	| 4 	|   	| Ans 	|
    |:--------------:	|:-:	|:-:	|:-:	|:-:	|:-:	|:-:	|:-:	|:---:	|
    | PrefixMod[idx] 	|   	| 1 	| 0 	| 0 	| 0 	| 0 	|   	|  0  	|
    |     nums[0]    	|   	| 1 	|   	|   	|   	| 1 	|   	|  0  	|
    |     nums[1]    	|   	| 1 	|   	|   	|   	| 2 	|   	|  1  	|
    |     nums[2]    	|   	| 1 	|   	| 0 	|   	| 3 	|   	|  3  	|
    |     nums[3]    	|   	| 1 	|   	| 1 	|   	| 3 	|   	|  3  	|
    |     nums[4]    	|   	| 1 	|   	| 1 	|   	| 4 	|   	|  6  	|
    |     nums[5]    	|   	| 2 	|   	| 1 	|   	| 4 	|   	|  7  	|
