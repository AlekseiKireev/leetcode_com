https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/description/ -- Subscribe to unlock.

https://www.lintcode.com/problem/911/

https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0325.Maximum%20Size%20Subarray%20Sum%20Equals%20k/README_EN.md

https://walkccc.me/LeetCode/problems/325/

| Idx  	|   	| 0 	| 1  	| 2 	| 3  	| 4 	| 5 	|
|------	|---	|---	|----	|---	|----	|---	|---	|
| Pref 	|   	| 0 	| 1  	| 0 	| 5  	| 3 	| 6 	|
| Nums 	|   	| 1 	| -1 	| 5 	| -2 	| 3 	|   	|

https://ru.algorithmica.org/cs/range-queries/prefix-sum/

- $PS_0 = 0$
- $PS_l = \sum_{i=0}^{l-1}a_i : l \geq 1$
- $PS_n - PS_k = f[a_k, ..., a_{n-1}]$
- $n-1 - k + 1 = n-k$ элементов в окне $[k, ..., n-1]$ - т.е. разность индексов префиксных сумм равна коли-у элементов в отрезке
