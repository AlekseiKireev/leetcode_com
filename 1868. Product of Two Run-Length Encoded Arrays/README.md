https://leetcode.com/problems/product-of-two-run-length-encoded-arrays/ -- CLOSED == premium

https://walkccc.me/LeetCode/problems/1868/

https://github.com/doocs/leetcode/blob/main/solution/1800-1899/1868.Product%20of%20Two%20Run-Length%20Encoded%20Arrays/README_EN.md

У Федора Меньшикова разбор отсут-т!

_______

[run-length encoding, RLE](https://ru.wikipedia.org/wiki/%D0%9A%D0%BE%D0%B4%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5_%D0%B4%D0%BB%D0%B8%D0%BD_%D1%81%D0%B5%D1%80%D0%B8%D0%B9)

_______

<p align="center"> My ex 1 </p>

    encoded1 = [ [10, 2], [7,1], [3, 2], [17,1] ]
    encoded2 = [ [11, 3], [15, 3] ]

|    idx   	|   	|    0    	|    1    	|       2      	|    3   	| 4            	|
|:--------:	|:-:	|:-------:	|:-------:	|:------------:	|:------:	|--------------	|
|          	|   	|         	|         	|              	|        	|              	|
| encoded1 	|   	| [10, 2] 	|  [7,1]  	|    [3, 2]    	| [17,1] 	| end_encoded1 	|
|   idx1   	|   	|   ^^^   	|         	|              	|        	|              	|
|          	|   	|         	|         	|              	|        	|              	|
| encoded2 	|   	| [11, 3] 	| [15, 3] 	| end_encoded2 	|        	|              	|
|   idx2   	|   	|   ^^^   	|         	|              	|        	|              	|



|    idx   	|   	|    0    	|    1    	|       2      	|    3   	| 4            	|
|:--------:	|:-:	|:-------:	|:-------:	|:------------:	|:------:	|--------------	|
|          	|   	|         	|         	|              	|        	|              	|
| encoded1 	|   	| [10, 2] 	|  [7,1]  	|    [3, 2]    	| [17,1] 	| end_encoded1 	|
|   idx1   	|   	|         	|   ^^^   	|              	|        	|              	|
|          	|   	|         	|         	|              	|        	|              	|
| encoded2 	|   	| [11, 3] 	| [15, 3] 	| end_encoded2 	|        	|              	|
|   idx2   	|   	|   ^^^   	|         	|              	|        	|              	|

|    idx   	|   	|    0    	|    1    	|       2      	|    3   	| 4            	|
|:--------:	|:-:	|:-------:	|:-------:	|:------------:	|:------:	|--------------	|
|          	|   	|         	|         	|              	|        	|              	|
| encoded1 	|   	| [10, 2] 	|  [7,1]  	|    [3, 2]    	| [17,1] 	| end_encoded1 	|
|   idx1   	|   	|         	|         	|      ^^^     	|        	|              	|
|          	|   	|         	|         	|              	|        	|              	|
| encoded2 	|   	| [11, 3] 	| [15, 3] 	| end_encoded2 	|        	|              	|
|   idx2   	|   	|         	|   ^^^   	|              	|        	|              	|



|    idx   	|   	|    0    	|    1    	|       2      	|    3   	| 4            	|
|:--------:	|:-:	|:-------:	|:-------:	|:------------:	|:------:	|--------------	|
|          	|   	|         	|         	|              	|        	|              	|
| encoded1 	|   	| [10, 2] 	|  [7,1]  	|    [3, 2]    	| [17,1] 	| end_encoded1 	|
|   idx1   	|   	|         	|         	|              	|   ^^^  	|              	|
|          	|   	|         	|         	|              	|        	|              	|
| encoded2 	|   	| [11, 3] 	| [15, 3] 	| end_encoded2 	|        	|              	|
|   idx2   	|   	|         	|   ^^^   	|              	|        	|              	|



|    idx   	|   	|    0    	|    1    	|       2      	|    3   	| 4            	|
|:--------:	|:-:	|:-------:	|:-------:	|:------------:	|:------:	|--------------	|
|          	|   	|         	|         	|              	|        	|              	|
| encoded1 	|   	| [10, 2] 	|  [7,1]  	|    [3, 2]    	| [17,1] 	| end_encoded1 	|
|   idx1   	|   	|         	|         	|              	|        	|      ^^^     	|
|          	|   	|         	|         	|              	|        	|              	|
| encoded2 	|   	| [11, 3] 	| [15, 3] 	| end_encoded2 	|        	|              	|
|   idx2   	|   	|         	|         	|      ^^^     	|        	|              	|
