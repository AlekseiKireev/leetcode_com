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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* ReverseNodes = nullptr; // в цикле обязательно должно быть обновление Node для ReverseNodes

        while(head != nullptr){

            // применене константности будет тут ошибкой! Это указатель на НЕ реверсивную часть списка
            ListNode* NextNode = head->next; // далее эта связь будет разорвана, необходимо ее сохранить

            head->next = ReverseNodes; // перебрасываем link на иную Node с целью разворота
            ReverseNodes = head; // обновляем указатель на ответ сдвигая его

            head = NextNode; // в цикле обязательно должно быть обновление head
        }

        return ReverseNodes;

    }
};
