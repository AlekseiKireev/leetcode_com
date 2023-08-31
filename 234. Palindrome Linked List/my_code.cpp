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

void ListReverse(){
    
}

public:
    bool isPalindrome(ListNode* head) {
        
    }
};
