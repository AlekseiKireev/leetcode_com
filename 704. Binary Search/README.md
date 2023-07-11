https://leetcode.com/problems/binary-search/description/

[Разбор задачи 704 leetcode.com Binary Search. Решение на C++](https://www.youtube.com/watch?v=VL30zBhwjMQ)

upper_bound.cpp - upper_bound

704a.cpp - lower_bound

704b.cpp

704c.cpp

_______________


target = 3

| void 	| nums.begin() 	| nums.end() 	|     nums_it 	|
|------	|---	|------------	|:-----------:	|
|     	| 5 	|            	|     nums    	|
|      	|  ^	|           	| upper_bound 	|
|      	|  ^ 	|            	| lower_bound 	|


target = 5

| void 	| nums.begin() 	| nums.end() 	|     nums_it 	|
|------	|---	|------------	|:-----------:	|
|     	| 5 	|   	        |     nums    	|
|      	|   	|      ^     	| upper_bound 	|
|      	| ^ 	|            	| lower_bound 	|


target = 7

| void 	| nums.begin() 	| nums.end() 	|     nums_it 	|
|------	|---	|------------	|:-----------:	|
|   	  | 5 	|     	      |      nums   	|
|      	|   	|      ^     	| upper_bound 	|
|      	|  	  |      ^    	| lower_bound 	|


На основе примеров можно утвнрждать, что если существует auto ItCheck = prev(ranges::upper_bound(nums, target)), то надо проверить на истиность *ItCheck == target -- если истино, возвращаем индекс, иначе возвращаем -1
