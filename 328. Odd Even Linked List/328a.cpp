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
    ListNode headl;
    ListNode head2;
    ListNode* lastl = &headl;
    ListNode* last2 = &head2;
    ListNode* p = head;
    while (true) {
      if (p == nullptr) {
        break;
      }
      lastl->next = p;
      lastl = p;
      p = p->next;
      if (p == nullptr) {
        break;
      }
      last2->next = p;
      last2 = p;
      p = p->next;
    }
    lastl->next = head2.next; 
    last2->next = nullptr;
    return headl.next;
  }
};
