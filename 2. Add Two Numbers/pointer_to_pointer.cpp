class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode Ans; // Ans pointer to the prev(begin)
        
        assert(Ans.val == 0);
        assert(Ans.next == nullptr);
 
        ListNode* Data = &Ans;
 
        assert(Data->val == 0);
        assert(Data->next == nullptr);
 
        int carry = 0;
 
        while(carry != 0 || l1 != nullptr || l2 != nullptr){
 
            int BitAmount = carry;
            
            for(ListNode**  l : vector<ListNode**>{&l1, &l2}){
 
                if(*l != nullptr){
                    
                    BitAmount += (*l)->val;
                    *l = (*l)->next;
                }
            }
 
            Data->next = new ListNode(BitAmount % 10);
            Data = Data->next;
            carry =  BitAmount >= 10;
 
 
        }
 
        return Ans.next;
 
    }
};

/*

            for(ListNode*  l : vector<ListNode*>{l1, l2}){
 
                if(l != nullptr){
                    
                    BitAmount += l->val;
                    l = l->next;
 
                }
            }

Anton Borzenko, [8/8/2023 11:13 AM]
> vector<ListNode*>{l1, l2}

в данной строчке ты создаешь вектор с копиями поинтеров.

Anton Borzenko, [8/8/2023 11:14 AM]
> for(ListNode*  l : vector<ListNode*>{l1, l2}){
итерируя таким образом, ты перекопируешь поинтер еще раз

и копию копии ты изменяешь )

А Б, [8/8/2023 11:16 AM]
Хм, то есть через for вообще никак, надо отдельно каждый if прописывать?

Anton Borzenko, [8/8/2023 11:25 AM]
можно через указатели на указатели попробовать (что очень некрасиво) https://leetcode.com/problems/add-two-numbers/submissions/1015454410/
можно через ссылки

Anton Borzenko, [8/8/2023 11:26 AM]
но когда у тебя всего 2 элемента, лучше всего работает ctrl-c ctrl-v как с точки зрения оптимизации кода, так и читаемости
*/
