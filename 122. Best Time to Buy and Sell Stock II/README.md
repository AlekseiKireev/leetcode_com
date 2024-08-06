https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

related: https://github.com/SkosMartren/leetcode_com/tree/main/121.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock

Сначала покупаем при убывании стоимости, затем продаем пока возрастает стоимость 

Total = 0

find Buy

| prices 	|   	| 7   	| 1 	| 5 	| 3 	| 6 	| 4 	|
|--------	|---	|-----	|---	|---	|---	|---	|---	|
| i      	|   	| ^^^ 	|   	|   	|   	|   	|   	|



| prices 	|   	| 7   	| 1 	| 5 	| 3 	| 6 	| 4 	|
|--------	|---	|-----	|---	|---	|---	|---	|---	|
| i      	|   	|     	| ^^^ |   	|   	|   	|   	|

Buy = 1

find Sell

| prices 	|   	| 7 	| 1 	| 5   	| 3 	| 6 	| 4 	|
|--------	|---	|---	|---	|-----	|---	|---	|---	|
| i      	|   	|   	|   	| ^^^ 	|   	|   	|   	|

Sell = 5

Total = 5-1


find Buy

| prices 	|   	| 7   	| 1 	| 5 	| 3 	| 6 	| 4 	|
|--------	|---	|-----	|---	|---	|---	|---	|---	|
| i      	|   	|     	|   	|   	| ^^^ |   	|   	|


Buy = 3

find Sell

| prices 	|   	| 7 	| 1 	| 5   	| 3 	| 6 	| 4 	|
|--------	|---	|---	|---	|-----	|---	|---	|---	|
| i      	|   	|   	|   	|     	|   	| ^^^ |   	|

Sell = 6

Total = 5-1+6-3 = 7


find Buy

| prices 	|   	| 7   	| 1 	| 5 	| 3 	| 6 	| 4 	|
|--------	|---	|-----	|---	|---	|---	|---	|---	|
| i      	|   	|     	|   	|   	|     |     | ^^^ |


Buy = 4

find Sell

| prices 	|   	| 7 	| 1 	| 5   	| 3 	| 6 	| 4 	|
|--------	|---	|---	|---	|-----	|---	|---	|---	|
| i      	|   	|   	|   	|     	|   	|     | ^^^ |

Sell = 4

Total = 5-1+6-3+4-4=7
