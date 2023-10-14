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
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) { 
      return head;
    }
    ListNode* firstEven = head->next; 
    ListNode* lastOdd = head;
    bool odd = true;
    for (ListNode* p = head; p != nullptr; ) {
      if (odd) {
        lastOdd = p;
      }
      ListNode* next = p->next; 
      if (next != nullptr) {
        p->next = next->next;
      }
      p = next;
      odd = !odd;
    }
    lastOdd->next = firstEven; 
    return head;
  }
};
