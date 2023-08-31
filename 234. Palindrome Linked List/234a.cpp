const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

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

  int getLen(ListNode* node) { 
   int len = 0;
   while (node != nullptr) { 
     node = node->next; 
     len++;
   }
   return len;
  }

/*
  ListNode* forward(ListNode* node, int steps) { 
   
   for (;steps > 0;steps--) {node = node->next;}
   return node;
   
  }
*/

  ListNode* forward(ListNode* node, int steps) { 
   while (steps > 0) {
     node = node->next;
     steps--;
    }
   return node;
  }

  ListNode* reverse(ListNode* head) {  // <-- https://github.com/SkosMartren/leetcode_com/tree/main/206.%20Reverse%20Linked%20List
   ListNode* ans = nullptr;
   while (head != nullptr) {
     ListNode* node = head;
     head = head->next;
     node->next = ans;
     ans = node;
   }
   return ans;
  }

public:

  bool isPalindrome(ListNode* head) {
   int len = getLen(head);
   ListNode* half2 = forward(head, (len + 1) / 2);  // <--> ListNode* half2 = forward(head, (len /*+ 1*/) / 2); 
   ListNode* last = reverse(half2);
   ListNode* node1 = head; 
   ListNode* node2 = last; 
   while (node2 != nullptr) {
     if (node1->val != node2->val) {
       
       // Обсудить с интервьюером, можно ли менять исходный head и будет ли приемлемо, что после результата работы функции head = 1->2->3->3<-2<-1 -- то есть указатели будут изменены
       //reverse(last);
       return false;
     }
     node1 = node1->next; 
     node2 = node2->next;
   }
   
   // Обсудить с интервьюером, можно ли менять исходный head и будет ли приемлемо, что после результата работы функции head = 1->2->3->3<-2<-1 -- то есть указатели будут изменены
   //reverse(last); 
   return true;
  }

};
/*
"+1" не обязательно, без него задача сдается, проверено

Разница для нечётной длины. 
Вот если длина 5 - нужно пропустить 2 элемента или 3, чтобы была вторая половина? 
Если пропустим 2, попадём ровно на центр, который сравнивать бессмысленно.
*/
