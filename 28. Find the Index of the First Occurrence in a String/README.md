https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

https://walkccc.me/LeetCode/problems/0028/

У Федора Меньшикова разбор отсут-т!

____________

Положим, что extreme -- крайний индекс, который может быть передан в качестве аргумента в substr. Тогда (haystack.size() - 1) - (extreme) + 1 = needle.size() <--> 
extreme = haystack.size() - needle.size() -- оценка сверху на первый аргумент substr, в который передается значение счетчика, поэтому само значение счетчика может быть ограничено сверху, например, так: i < haystack.size() - needle.size() + 1 --> крайнее значение i равно haystack.size() - needle.size()

| Idx           	|   	| 0    	| 1    	| ... 	| extreme 	| ... 	| haystack.size() - 1 	|
|---------------	|---	|------	|------	|-----	|---------	|-----	|---------------------	|
| haystack == h 	|   	|      	|      	|     	|         	|     	|                     	|
| needle == n   	|   	| n[0] 	| n[1] 	|     	|         	|     	|                     	|
