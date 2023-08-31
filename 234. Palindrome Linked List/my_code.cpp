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

private:

  int ListSize(ListNode* head){

    int Size = 0;

    while(head != nullptr){
        head = head->next;
        ++Size;
    }

    return Size;

  }

/*
 1 -> 2 -> 3 -> nullptr
 ^      
 |
head

 1 -> 2 -> 3 -> nullptr
 ^    ^      
 |    |
PNH  head

Ввиду следующего графика видим необходимость переброски указателя head->next на HLR,
но при этом надо не потерять "хвост" в виде "2 -> 3 -> nullptr" -- на него тоже нужен указатель!

nullptr <- 1    2 -> 3 -> nullptr

nullptr <- 1    2 -> 3 -> nullptr
    ^           ^
    |           |
   HLR         head

nullptr <- 1    2 -> 3 -> nullptr
           ^    ^
           |    |
          HLR  head
   
nullptr <- 1 <- 2    3 -> nullptr

 nullptr <- 1 <- 2 <- 3
                      ^      
                      |
                     HLR

3 -> 2 -> 1 -> nullptr
^      
|
HLR

head в конечном итоге == nullptr
*/

  ListNode* ListReverse(ListNode* head){
      
    ListNode* HeadListReverse = nullptr; // == HLR

    while(head != nullptr){

        ListNode* PrevNodeHead = head; // == PNH
        head = head->next;

        PrevNodeHead->next = HeadListReverse;
        HeadListReverse = PrevNodeHead;

    }

    return HeadListReverse;

  }

ListNode* CentrePalindrome(ListNode* head, int CoordinateCentre){

    while(CoordinateCentre > 0){
      head = head->next;
      --CoordinateCentre;
    }

    return head;
}

public:

    bool isPalindrome(ListNode* head) {
      
      int Size = ListSize(head);
      ListNode* Centre = CentrePalindrome(head, Size / 2);
      ListNode*  LastNode = ListReverse(Centre);

      while(LastNode != nullptr){

        if(LastNode->val != head->val){return false;}
        head = head->next;
        LastNode = LastNode->next;
      }

      return true;
    }

};
