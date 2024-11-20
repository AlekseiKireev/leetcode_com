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
/*
Time complexity : O(n+m)
Space complexity : O(1)
*/
class Solution {

public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode Ans(-1);

        ListNode* Cur = &Ans;

        while(true){

            if(list1 == nullptr && list2 == nullptr){
                break;
            }

            if(list1 == nullptr){
                Cur->next = list2;
                break;
            }

            if(list2 == nullptr){
                Cur->next = list1;
                break;
            }

            if(list2->val < list1->val){
                Cur->next = list2;
                list2 = list2->next;
            }else{
                Cur->next = list1;
                list1 = list1->next;                
            }
            
            Cur = Cur->next;
            
        }

        return Ans.next;
        
    }

};
