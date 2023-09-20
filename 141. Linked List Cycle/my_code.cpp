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
    bool hasCycle(ListNode *head) {
        
        ListNode * Slow = head;
        ListNode * Fast = head;

        while(true){

            if(Fast == nullptr){return false;}
            Slow = Slow->next;
            Fast = Fast->next;
            if(Fast == nullptr){return false;}
            Fast = Fast->next;
            //if(Fast == nullptr){return false;} // Wrong Answer 21 / 23 testcases  Input [1,1,1,1] -1 Use Testcase Output true Expected false
            // if(Fast->val == Slow->val){return true;} // ввиду комментария в 23 строке этот условный оператор не валиден!
            if(Fast == Slow){return true;}

        }

        return true;
    }
};
