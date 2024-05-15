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
head / Ans стоит отождествить со стеком дляя простоты восприятия
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        /*0*/ ListNode* Ans = nullptr;

        while (head != nullptr) {

            /*1*/ ListNode* prev = head;
            /*2*/ head = head->next;
            /*3*/ prev->next = Ans;
            /*4*/ Ans = prev;
        }


        return Ans;

    }
};
/*

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* ReverseNodes = nullptr; // в цикле обязательно должно быть обновление Node для ReverseNodes

        for(; head != nullptr; ){

            // применене константности будет тут ошибкой! Это указатель на НЕ реверсивную часть списка
            ListNode* NextNode = head->next; // далее эта связь будет разорвана, необходимо ее сохранить

            head->next = ReverseNodes; // перебрасываем link на иную Node с целью разворота
            ReverseNodes = head; // обновляем указатель на ответ сдвигая его

            head = NextNode; // в цикле обязательно должно быть обновление head
        }

        return ReverseNodes;

    }
};
*/
