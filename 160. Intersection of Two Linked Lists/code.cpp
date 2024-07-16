/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // если не будет копий, то в цикле будем сдвигать оригинал, ввиду чего, например, при A = headB получится, что A не указывает на начало headB
        ListNode *A = headA;
        ListNode *B = headB;

        while(A!=B){

            A = (A == nullptr) ? headB : A->next;
            B = (B == nullptr) ? headA : B->next;
        }

        return A;
    }
};
