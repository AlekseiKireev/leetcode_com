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

    // Garbage == nth_Node
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* Right = head;

        for(int i = 0; i < n; ++i){
            Right = Right->next;
        }

        // дошли до конца списка --> head.size() == n  --> у удаляемого элеменат Garbage нет prev(Garbage), т.е. удаляем первый элемент листа
        if(Right == nullptr){ 
            ListNode* Garbage = head;
            head = head->next;
            delete Garbage;
            return head;
        }

        // псевдокод:
        // assert(n < head.size()) 
        // иначе у удаляемого элемента, ввиду assert [инварината], Garbage есть элемент в списке, предщестсвующей удаляемому -- prev(Garbage)
        // и есть next(Garbage), возможно, равный nullptr

        ListNode* Left = head;
        while(Right->next != nullptr){ // условие выхода из цикла можно прочуст-ь на примере "Ex 1 for alg 2."

            Right = Right->next; 
            Left = Left->next; // ожидается, что Left указывает на prev(Garbage)
        }

            ListNode* Garbage = Left->next;
            Left->next = Left->next->next;
            delete Garbage;
            return head;
    }


};
