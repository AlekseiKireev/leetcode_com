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

        /*0*/ ListNode* Ans = nullptr;

        while (head != nullptr) {

            /*1*/ ListNode* prev = head;
            /*2*/ head = head->next;
            /*3*/ prev->next = Ans;
            /*4*/ Ans = prev;
        }


        return Ans;

    }
};
