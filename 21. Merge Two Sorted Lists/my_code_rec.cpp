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

    if (list1 == nullptr || list2 == nullptr){ return list1 ? list1 : list2; }

    if (list1->val > list2->val){ swap(list1, list2); }
    
    assert(list1->val <= list2->val);

    list1->next = mergeTwoLists(list1->next, list2);

    return list1;
  }

};

/*

// https://leetcode.com/problems/merge-two-sorted-lists/submissions/

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  {

		if(l1 == NULL){return l2;}

		if(l2 == NULL){return l1;} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
		if(l1 -> val <= l2 -> val){
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		// we will call recursive l1 whole list and l2 -> next
		else{
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}
};	

*/
