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
Time complexity : O(logK*KN)
Space complexity : O(kN)
*/
class Solution {

private:

    ListNode* mergeTwoLists(ListNode* a, ListNode* b){

        if(a == nullptr){
            return b;
        }
        if(b == nullptr){
            return a;
        }

        if(a->val < b->val){

            a->next = mergeTwoLists(a->next, b);
            return a;

        }else{

            b->next = mergeTwoLists(a, b->next);
            return b;

        }
    }   

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){return nullptr;}
        deque<ListNode*> LISTS( std::make_move_iterator(lists.begin()),
                                std::make_move_iterator(lists.end()));

        while(LISTS.size() != 1){

            LISTS.push_back(mergeTwoLists(LISTS[0], LISTS[1]));
            LISTS.pop_front();LISTS.pop_front();
        }

        return LISTS.front();
    }
};
