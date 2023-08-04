https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

https://walkccc.me/LeetCode/problems/0121/

<p align="center"> два указателя </p>

<p align="center"> Example 1: </p>

prices = [7,1,5,3,6,4]

| i 	| _prices[i]_ 	| _MinPrice_ 	| **MaximumProfit** 	|
|:-:	|:-----------:	|:----------:	|:-----------------:	|
| 0 	|     _7_     	|     _7_    	|       **0**       	|
| 1 	|     _1_     	|     _1_    	|       **0**       	|
| 2 	|     _5_     	|     _1_    	|       **4**       	|
| 3 	|     _3_     	|     _1_    	|       **4**       	|
| 4 	|     _6_     	|     _1_    	|       **5**       	|
| 5 	|     _4_     	|     _1_    	|       **5**       	|

<p align="center"> Динамическое программирование </p>

<p align="center"> Example 1: </p>

prices = [7,1,5,3,6,4]

| i 	| _prices[i]_ 	| _maxPrices[i]_ 	| **MaximumProfit** 	|
|---	|-------------	|-------------	|-------------------	|
| 0 	| _7_         	| _7_         	| **0**             	|
| 1 	| _1_         	| _6_         	| **5**             	|
| 2 	| _5_         	| _6_         	| **1**             	|
| 3 	| _3_         	| _6_         	| **3**             	|
| 4 	| _6_         	| _6_         	| **0**             	|
| 5 	| _4_         	| _4_         	| **0**             	|



MaximumProfit = max{maxPrices[i] - prices[i] : 0 <= i <= prices.size() - 1}

maxPrices[i] - максимальная цена акции, по которой можно продать в i-ый день. 
Так как максимальная цена может быть достигнута в день d > i, надо заполнять этот контейнер справа налево  
maxPrices[i] = либо prices[i], либо maxPrices[i + 1] -- из этих значений берется максимум. 
То есть, 
либо максимальная цена была в день d > i --> maxPrices[i] = maxPrices[i + 1], 
либо максимальная цена в день i --> maxPrices[i] = prices[i]


<p align="center"> Example 2: </p>

| i 	| _prices[i]_ 	| _maxPrices_ 	| **MaximumProfit** 	|
|---	|-------------	|-------------	|-------------------	|
| 0 	| _7_         	| _7_         	| **0**             	|
| 1 	| _6_         	| _6_         	| **0**             	|
| 2 	| _4_         	| _4_         	| **0**             	|
| 3 	| _3_         	| _3_         	| **0**             	|
| 4 	| _1_         	| _1_         	| **0**             	|
