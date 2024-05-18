https://leetcode.com/problems/design-hit-counter/ -- CLOSED == premium

related: 
- https://github.com/SkosMartren/leetcode_com/tree/main/933.%20Number%20of%20Recent%20Calls  -- аналог my_code_queue.cpp

https://walkccc.me/LeetCode/problems/0362/ -- ОЗНАКОМИТЬСЯ И ПОПЫТАТЬСЯ РЕАЛИЗОВАТЬ ТАК В 933

https://github.com/doocs/leetcode/tree/main/solution/0300-0399/0362.Design%20Hit%20Counter

У Федора Меньшикова разбор отсут-т!

_____________

 you may assume that calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing). -- на самом деле не убывает, можно это увидеть на примере вызова hit(300) и последующего getHits(300)  

|                                idx                                	|   	| 0 	| 1 	| 2 	|         	| 3   	|           	|         	|
|:-----------------------------------------------------------------:	|:-:	|:-:	|:-:	|---	|---------	|-----	|-----------	|---------	|
|                           t from hit(t)                           	|   	| 1 	| 2 	| 3 	|         	| 300 	|           	|         	|
|                         t from getHits(t)                         	|   	|   	|   	|   	| 4       	|     	| 300       	| 301     	|
| idx-based certificate (колич-о элем-тов в полуинтервале (t-300, t] )|   	|   	|   	|   	| {0,1,2} 	|     	| {0,1,2,3} 	| {1,2,3} 	|


___


https://www.geeksforgeeks.org/design-a-hit-counter/

https://cheonhyangzhang.gitbooks.io/leetcode-solutions/content/362-design-hit-counter.html

https://wentao-shao.gitbook.io/leetcode/data-structure/362.design-hit-counter

https://aaronice.gitbook.io/lintcode/data_structure/design-hit-counter

https://www.lintcode.com/problem/3662/

https://leetcode.ca/2016-11-26-362-Design-Hit-Counter/
