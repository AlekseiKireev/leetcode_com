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
        
        ListNode* Buffer = head;
        int Len = 0;
        while(Buffer != nullptr){
            ++Len;
            Buffer = Buffer->next;
        }

        // дошли до конца списка --> у удаляемого элеменат Garbage нет prev(Garbage), т.е. удаляем первый элемент листа
        if(Len == n){

            ListNode* Garbage = head;
            head = head->next;
            delete Garbage;
            return head;

        }

        assert(n < Len);

        Buffer = head;
        for(int i = 0; i < Len - n - 1; ++i){ // условие выхода из цикла можно прочуст-ь на примере "Ex 1 for alg 1."
            Buffer = Buffer->next;
        } // Buffer == prev(Garbage)

        ListNode* Garbage = Buffer->next;

        Buffer -> next = Buffer->next -> next;
        delete Garbage;
        return head;

    }

};
