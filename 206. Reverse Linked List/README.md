https://leetcode.com/problems/reverse-linked-list/

https://walkccc.me/LeetCode/problems/0206/

[Разбор задачи 206 leetcode.com Reverse Linked List. Решение на C++](https://www.youtube.com/watch?v=jqZPEfAbc2s) --  iteratively and recursively

[Software interview question - Reverse a linked list recursively](https://www.youtube.com/watch?v=S92RuTtt9EE)


____

<p align="center"> iteratively </p>

https://www.geeksforgeeks.org/reverse-a-linked-list/

<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif" width="800" height="500"/>

По сути решение происходит через абстракцию 2-х стеков

<p align="center"> /*0*/ </p>

| NULL 	|   	| 1    	| -> 	| 2 	| -> 	| 3 	| -> 	| NULL 	|
|------	|---	|------	|----	|---	|----	|---	|----	|------	|
| ^^^  	|   	| ^^^  	|    	|   	|    	|   	|    	|      	|
| Ans  	|   	| head 	|    	|   	|    	|   	|    	|      	|

<p align="center"> /*1*/ </p>

| NULL 	|   	| 1              	| ->	| 2 	| -> 	| 3 	| -> 	| NULL 	|
|------	|----	|----------------	|---	|---	|----	|---	|----	|------	|
| ^^^  	|    	| ^^^            	|   	|   	|    	|   	|    	|      	|
| Ans  	|    	| head <br> prev 	|   	|   	|    	|   	|    	|      	|

<p align="center"> /*2*/ </p>

| NULL 	|   	| 1    	| -> 	| 2    	| -> 	| 3 	| -> 	| NULL 	|
|------	|---	|------	|----	|------	|----	|---	|----	|------	|
| ^^^  	|   	| ^^^  	|    	| ^^^  	|    	|   	|    	|      	|
| Ans  	|   	| prev 	|    	| head 	|    	|   	|    	|      	|

<p align="center"> /*3*/ </p>

| NULL 	| <- 	| 1    	|   	| 2    	| -> 	| 3 	| -> 	| NULL 	|
|------	|----	|------	|---	|------	|----	|---	|----	|------	|
| ^^^  	|    	| ^^^  	|   	| ^^^  	|    	|   	|    	|      	|
| Ans  	|    	| prev 	|   	| head 	|    	|   	|    	|      	|

<p align="center"> /*4*/ </p>

| NULL 	| <- 	| 1                     	|   	| 2    	| -> 	| 3 	| -> 	| NULL 	|
|------	|----	|-----------------------	|---	|------	|----	|---	|----	|------	|
|      	|    	| ^^^                   	|   	| ^^^  	|    	|   	|    	|      	|
|      	|    	| prev <br> == <br> Ans 	|   	| head 	|    	|   	|    	|      	|


И так далее 1 - 4, до тех пор, пока head != nullptr
____

Vladislav 🇺🇸🚜, [8/7/2023 12:26 AM]
разница в том, что значение head->next уже поменялось

Leonid, [8/7/2023 12:27 AM]
в неправильных решениях ты в первом же проходе определяешь для head следующую ноду ans, которая nullptr





    class Solution {
     public:
    
      ListNode* reverseList(ListNode* head) {
    
        ListNode* ans = nullptr;
    
        while (head != nullptr) {
    
          ListNode* node = head;
    
          //head = head->next; // good!
    
          node->next = ans;
    
          //head = head->next; // error 1!
          
          ans = node;
    
          //head = head->next; // error 1!
        }
    
        return ans;
      }
    };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


<p align="center"> recursively </p>

https://www.geeksforgeeks.org/reverse-a-linked-list/

<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/2009/07/Linked-List-Rverse.gif" width="790" height="520"/>

