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
надо удалить 4, т.е. n=2:
1	2	3	4	5	nullptr
L
R

сдвинем R на n:

1	2	3	4	5	nullptr
L
                R

после чего сдвигаем L, пока оно не будет перед удаляемым элементом

1	2	3	4	5	nullptr
                L
                                R       R->next     
*/
/*
Time complexity: O(head.size())
Space complexity: O(1)
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
            head = head->next; // перебрасываем ссылку, т.е. из 1-2-3-4-5 делаем 1 2-3-4-5
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
            Left->next = Left->next->next; // из 1-2-3-4-5-null сделали 1-2-3 4 5-null и связали 3 с 5 (т.е. Left указывал на 3)
            delete Garbage;
            return head;
    }


};
