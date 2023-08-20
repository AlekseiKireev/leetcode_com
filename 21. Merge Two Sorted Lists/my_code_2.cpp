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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

	if(list1 == nullptr){return list2;}

	if(list2 == nullptr) {return list1;}

        ListNode* Ans;

        if(list1->val < list2->val){
            Ans = list1;
            list1 = list1->next;
        }else{
            Ans = list2;
            list2 = list2->next;            
        }

        ListNode* Cur = Ans;

        while(list1 != nullptr && list2 != nullptr){

            if(list1->val < list2->val){
                Cur->next = list1;
                list1 = list1->next;
            }else{
                Cur->next = list2;
                list2 = list2->next;            
            }            
            
            Cur = Cur->next;

        }

        Cur->next = ((list1 == nullptr) ? list2 : list1);
        return Ans;
      
    }

};
