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
        
        ListNode* RightPtr = head;
        for(;0 < n; --n){
            RightPtr = RightPtr->next;
        }

        if(RightPtr == nullptr){ // удаление 1 элемента
            head = head->next; 
            return head;
        }

        ListNode* LeftPtr = head; // будет указывать на ближайший слева элемент, который надо удалить
        for(;RightPtr->next != nullptr; RightPtr = RightPtr->next){ // RightPtr->next != nullptr следует из примера Input: head = [1,2,3,4,5], n = 2 Output: [1,2,3,5] -- можно легко это прочувствовать
            LeftPtr = LeftPtr->next;
        }

        LeftPtr->next = LeftPtr->next->next;

        return head;

    }
};
