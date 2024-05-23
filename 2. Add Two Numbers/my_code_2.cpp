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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* Ans = new ListNode();
        ListNode* Data = Ans;

        int carry = 0;

        while(carry != 0 || l1 != nullptr || l2 != nullptr){

            int Sum = carry;

            if(l1 != nullptr){
                
                Sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                
                Sum += l2->val;
                l2 = l2->next;
            }

            Data -> next  = new ListNode(Sum % 10);

            assert(!Data -> next-> next); // Data -> next-> next == nullptr
            Data = Data -> next;

            carry = (Sum >= 10);
        }

        return Ans->next;
    }
};

/*

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // "linked lists representing two non-negative integers"
        ListNode* TotalSum = new ListNode(-1); // без создания элемента будетт ошикба!
        ListNode* Buffer = TotalSum;

        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0){

            int First = (l1 == nullptr) ? 0 : l1->val;
            int Second = (l2 == nullptr) ? 0 : l2->val;

            Buffer->next = new ListNode((First + Second + carry) % 10);
            Buffer = Buffer->next;

            carry = (First + Second + carry) / 10;
            if(l1 != nullptr){l1 = l1->next;}
            if(l2 != nullptr){l2 = l2->next;}

        }

        Buffer->next = nullptr;
        return TotalSum->next; // создали виртуальный элемент для того, чтобы ссылка не указвала  

    }
};
*/
