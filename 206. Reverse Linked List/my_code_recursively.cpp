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

    ListNode* Ans = reverseList(head->next); // Ans указывает на последний [не nullptr] элемент исходного листа

    assert(head->next->next == nullptr);
    head->next->next = head;

   // nullptr -- буффер для зацепки следующий ноды, если head != head.begin()
    head->next = nullptr; // загатовка для предыдущего шага рекурсии, чтобы в нем имело место утверждение: head->next->next == nullptr
    return Ans;
  }
};
