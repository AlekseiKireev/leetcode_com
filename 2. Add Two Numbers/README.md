

Почему  
в конце beforeRes.next -- вызывается по умолчанию при написании ListNode beforeRes;  
во всех решениях два контейнера -- один контейнер указывет на свой конец, второй на ведущий ноль   

А Б, [5/23/2024 5:43 PM]
а почему будет ошибка, если написать: 

        ListNode* TotalSum ;
        ListNode* Buffer = TotalSum;

почему надо инациализировать значение TotalSum?

Dmitrii Kochetov, [5/23/2024 5:46 PM]
Потому что так ты создаёшь пустой указатель 
ListNode* TotalSum;
Это равнозначно
ListNode* TotalSum = nullptr;

Сам объект, на который указывает указатель надо создавать через new ListNode()

А Б, [5/23/2024 5:47 PM]
вопрос глупый, но я его задам: nullptr же не может куда либо указывать, да?))

Dmitrii Kochetov, [5/23/2024 5:48 PM]
nullptr переводится, как нулевой указатель, то есть да, он ни на что не указывает

https://leetcode.com/problems/add-two-numbers/

- https://leetcode.com/problems/add-two-numbers/solutions/1340/a-summary-about-how-to-solve-linked-list-problem-c/

________

https://e-maxx.ru/algo/big_integer

        // /assert(nullptr == false);/ error!!
        assert(!nullptr);
        
________

https://walkccc.me/LeetCode/problems/0002/

[Разбор задачи 2 leetcode.com Add Two Numbers. Решение на C++](https://www.youtube.com/watch?v=QflftNTHeeE)

Сложение идет от младших разярдов к старшему, узнать какая сторона считается за младший разряд!

________

Аналог: [415. Add Strings](https://leetcode.com/problems/add-strings/description/)

https://github.com/SkosMartren/leetcode_com/tree/main/415.%20Add%20Strings


________

На основе примера:

|  l1 	| 9 	| 9 	| 9 	|nullptr|   	|
|---	|---	|---	|---	|---	|:-:	|
| + 	|   	|   	|   	|   	|   	|
|  l2 	| 2  	|nullptr|  	|   	|   	|
| - 	| - 	| - 	| - 	| - 	|   	|
|  Ans	| 1 	| 0 	| 0 	|  1 	|nullptr|
|carry  | 0 	| 1 	| 1 	|  0 	|   	|

Можно легко прочувствовать логическое условие "carry != 0 || l1 != nullptr || l2 != nullptr"

На самом деле Ans имеет вид: garbage --> 1 --> 0  --> 0  --> 1  --> nullptr -- поэтому надо возвращать next
____

        #include <iostream>
        
        struct ListNode {
            int val;
            ListNode* next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode* next) : val(x), next(next) {}
        };
        
        class Solution {
        public:
            ListNode* addTwoNumbers(ListNode* a, ListNode* b) { 
               ListNode beforeRes;
               ListNode *resLast = &beforeRes;
               int carry = 0;
               while (a != nullptr || b != nullptr || carry != 0) {
                 
                   int sum = carry;
                 
                   if (a != nullptr) { 
                      sum += a->val;
                      a = a->next;
                   }
                 
                   if (b != nullptr) { 
                      sum += b->val;
                      b = b->next;
                   }
                 
                   resLast->next = new ListNode(sum % 10); 
                   resLast = resLast->next;
                   carry = sum / 10;
                 
               }
               return beforeRes.next;
            }
        };
        
        int main() {
            // Создание двух простых списков: 243 и 564
            ListNode* list1 = new ListNode(2);
            list1->next = new ListNode(4);
            list1->next->next = new ListNode(3);
        
            ListNode* list2 = new ListNode(5);
            list2->next = new ListNode(6);
            list2->next->next = new ListNode(4);
        
            Solution solution;
            ListNode* result = solution.addTwoNumbers(list1, list2);
        
            // Вывод результата
            while (result != nullptr) {
                std::cout << result->val << " ";
                result = result->next;
            }
        
            return 0;
        }

_____

Лакман Макдауэл - Карьера программиста (2020)

условие: страница 87, задача 2.5.

решение: страница 220

