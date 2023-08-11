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

  ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    int len = 0;
    for (ListNode* p = head; p != nullptr; p = p->next)  {
      len++;
    }

    if (len == n) {
      ListNode* answer = head->next;
      delete head; 
      return answer;
    }

    assert(len > n); 
    ListNode* p = head;

    for (int i = 0; i < len - n - 1; i++) {
      p = p->next;
    }

    ListNode* toDelete = p->next; 
    p->next = p->next->next;
    delete toDelete;
    
    return head;
  }

};

