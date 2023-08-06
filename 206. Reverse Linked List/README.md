https://leetcode.com/problems/reverse-linked-list/

[Разбор задачи 206 leetcode.com Reverse Linked List. Решение на C++](https://www.youtube.com/watch?v=jqZPEfAbc2s) --  iteratively and recursively

[Software interview question - Reverse a linked list recursively](https://www.youtube.com/watch?v=S92RuTtt9EE)

____

Vladislav 🇺🇸🚜, [8/7/2023 12:26 AM]
разница в том, что значение head->next уже поменялось

Leonid, [8/7/2023 12:27 AM]
в неправильных решениях ты в первом же проходе определяешь для head следующую ноду ans, которая nullptr


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


    class Solution {
     public:
    
      ListNode* reverseList(ListNode* head) {
    
        ListNode* ans = nullptr;
    
        while (head != nullptr) {
    
          ListNode* node = head;
    
          head = head->next; // good!
    
          node->next = ans;
    
          //head = head->next; // error 1!
          
          ans = node;
    
          //head = head->next; // error 1!
        }
    
        return ans;
      }
    };
