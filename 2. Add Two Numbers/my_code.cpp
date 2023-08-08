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
        
        ListNode Ans = ListNode(); // Ans pointer to the prev(Ans.begin()) : prev(begin) -> val = 0
        
        assert(Ans.val == 0);
        assert(Ans.next == nullptr);

        ListNode* Data = &Ans; // Data as a result pointer to the prev(Ans.end()) 

        assert(Data->val == 0);
        assert(Data->next == nullptr);

        int carry = 0;

        while(carry != 0 || l1 != nullptr || l2 != nullptr){

            int BitAmount = carry;
            

            if(l1 != nullptr){
                
                BitAmount += l1->val;
                l1 = l1->next;

            }

            if(l2 != nullptr){
                
                BitAmount += l2->val;
                l2 = l2->next;

            }

            Data->next = new ListNode(BitAmount % 10);
            Data = Data->next;
            carry =  BitAmount >= 10;


        }

        //  Data pointer in the end Ans
        // cout << Data->val;
        
        return Ans.next; // обращается к полю next, который хранит указатель на следующей элемент 

    }
};
