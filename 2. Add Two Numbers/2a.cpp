class Solution {
public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) { 
       ListNode beforeRes;
        //assert(beforeRes == nullptr);
        assert(beforeRes.next == nullptr);
       ListNode *resLast = &beforeRes;
       int carry = 0;
       while (a != nullptr || b != nullptr || carry != 0) {
         
           int sum = carry;
         
           if (a != nullptr) { 
              sum += a->val;
              a = a->next;
           }
         
           if (b != nullptr) { 
              sum += b->val;
              b = b->next;
           }
         
           resLast->next = new ListNode(sum % 10); 
           resLast = resLast->next;
           carry = sum / 10;
         
       }
       return beforeRes.next;
    }
};

