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
Time complexity : O(n)
Space complexity : O(1)
*/
class Solution {

ListNode* FindRightMid(ListNode* head){
    ListNode* Slow = head;
    ListNode* Fast = head;

    while(Fast != nullptr && Fast->next != nullptr){
        Slow = Slow->next;
        Fast = Fast->next->next;
    }

    return Slow;
}


// https://github.com/SkosMartren/leetcode_com/tree/main/206.%20Reverse%20Linked%20List
ListNode* Reverse(ListNode* head){

    ListNode* ReverseNodes = nullptr;

    while(head != nullptr){

        ListNode* NextNode = head->next;
        head->next = ReverseNodes; // разрываем связь

        // перебрасываем указатели
        ReverseNodes = head;
        head = NextNode;

    }

    return ReverseNodes;
}

public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* RightPtr = Reverse(FindRightMid(head));

        while(RightPtr != nullptr){
            
            if(head->val != RightPtr->val){return false;}
            RightPtr = RightPtr->next;
            head = head->next;
        }

        return true;
    }
};
