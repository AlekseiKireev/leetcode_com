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

    // for "Example 3:"
    if(head == nullptr){
     cout << "head == nullptr\n"; 
     return nullptr;
    }

    // выход из рекурсии
    if (head->next == nullptr) {return head;}

    ListNode* Ans = reverseList(head->next); // Ans указывает на head->next

    head->next->next = head;
    head->next = nullptr; // зануляем связь?
    return Ans;
  }
};
