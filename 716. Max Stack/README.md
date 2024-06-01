https://leetcode.com/problems/max-stack/description/ - closed

https://www.lintcode.com/problem/859/

У Федора Меньшикова разбор отсут-т!

https://walkccc.me/LeetCode/problems/716/

https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0716.Max%20Stack/README_EN.md

related: https://github.com/SkosMartren/leetcode_com/tree/main/155.%20Min%20Stack

___

    class MaxStack {
    
    public:
    
        MaxStack() {
        }
    
        void push(int x) {
            
        }
    
        int pop() {
            
        }
    
        int top() {
            
        }
    
        int peekMax() {
            
        }
    
        int popMax() {
            
        }
    
    };
    
    /**
     * Your MaxStack object will be instantiated and called as such:
     * MaxStack* obj = new MaxStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->peekMax();
     * int param_5 = obj->popMax();
     */

___

Так как popMax может быть из любого места стека, то удобно использовать list<type(x)> OrderVal и удалять по итератору. Для удобства будем использовать push_front  

Обсудим оптимальное удаление и "If there is more than one maximum element, only remove the top-most one."

Для максимума будем использовать RBT и брать крайний элемент

# Плохая идея: метка времени

multimap< {x, time}, list<type(x)>::iterator > ValToItList
unordered_map<x, time> ValToCount

в качестве временных меток будет количество, т.е. 1 <= time -- если time = 0, удалены все элементы x

# Хорошая идея: в ДРМ push_back располагаются в порядке возрастания времени

map<x, vector<list<type(x)>::iterator> > ValToItsList

# вместо RBT можно использовать очередь с приоритетом?

___

А Б, [6/2/2024 12:19 AM]
код:  https://pastebin.com/YSRuTqtZ — почему он падает, но если закомментировать 18 строку, то все прекарсно работает, при этом код не сразу падает, а спустя какое-то врмя работы, говорит что вызван back от пустого вектора, но фактически не было такого обращения... в чем ошибка — не пойму...

https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0716.Max%20Stack/README_EN.md — если вдруг кому-то надо условие

Mikail Bagishov, [6/2/2024 12:28 AM]
ну то что он падает с раскомментированной строкой неудивительно, ты же сам себе инварианты ломаешь

А Б, [6/2/2024 12:53 AM]
не очень понял

* Да, у меня опечатка, падает при 18 раскомментированной строке

А Б, [6/2/2024 12:53 AM]
он говорит, что обращаюсь к back() у вектора, но явно там такого нет

Mikail Bagishov, [6/2/2024 12:54 AM]
ну да, раскомментировал, она тебе сломала инварианты (что в мапе нет пустых векторов) и ты потом крашнулся

А Б, [6/2/2024 12:54 AM]
мап не может содержать пустых векторов?

Mikail Bagishov, [6/2/2024 12:54 AM]
Может.
Но судя по твоему коду, у него есть такой инвариант.

Mikail Bagishov, [6/2/2024 12:59 AM]
так, ну у тебя после нескольких первых операций (сразу после push(-443) в стеке лежит только -443, насколько я вижу

Mikail Bagishov, [6/2/2024 12:59 AM]
поэтому когда после этого вызывается popMax, он в качестве максимума видит эту самую фейковую 24

Mikail Bagishov, [6/2/2024 12:59 AM]
ну и ломается об нее

Mikail Bagishov, [6/2/2024 1:07 AM]
Ну тут скорее не санитайзеры а  -D_GLIBCXX_DEBUG=1 -D_GLIBCXX_DEBUG_PEDANTIC=1 помогают

Mikail Bagishov, [6/2/2024 1:07 AM]
точнее санитайзеры, мб, тоже сработают, но менее прямо

        #include <iostream>
        #include <vector>
        #include <list>
        #include <map>
        #include <iterator>
        #include <functional>
        
        using namespace std;
        
        class MaxStack {
            list<int> OrderVal; // Хранит значения в порядке добавления
            map<int, vector<list<int>::iterator>, greater<int>> ValToItsOnVal; // Хранит итераторы значений, упорядоченные по убыванию
        
        public:
            MaxStack() {}
        
            void push(int x) {
                ValToItsOnVal[24];
                OrderVal.push_front(x);
                ValToItsOnVal[x].push_back(OrderVal.begin());
            }
        
            int pop() {
                const int ValTopStack = OrderVal.front();
                auto& VCT = ValToItsOnVal[ValTopStack];
                VCT.pop_back();
                if (VCT.empty()) {
                    ValToItsOnVal.erase(ValTopStack);
                }
                OrderVal.pop_front();
                return ValTopStack;
            }
        
            int top() {
                return OrderVal.front();
            }
        
            int peekMax() {
                return ValToItsOnVal.begin()->first;
            }
        
            int popMax() {
                const int ValMax = peekMax();
                auto& VCT = ValToItsOnVal[ValMax];
                OrderVal.erase(VCT.back());
                VCT.pop_back();
                if (VCT.empty()) {
                    ValToItsOnVal.erase(ValMax);
                }
                return ValMax;
            }
        };
        
        int main() {
            MaxStack stk;
            stk.push(430);
            cout << stk.popMax() << endl; // 430
            stk.push(234);
            cout << stk.top() << endl;    // 234
            cout << stk.popMax() << endl; // 234
            stk.push(-293);
            cout << stk.pop() << endl;    // -293
            stk.push(-443);
            cout << stk.popMax() << endl; // -443
            stk.push(349);
            cout << stk.popMax() << endl; // 349
            stk.push(1);
            cout << stk.peekMax() << endl; // 1
            cout << stk.popMax() << endl;  // 1
            stk.push(763);
            cout << stk.popMax() << endl;  // 763
            return 0;
        }

<br>

        Input Data
        push(430)
        popMax()
        push(234)
        top()
        popMax()
        push(-293)
        pop()
        push(-443)
        popMax()
        push(349)
        popMax()
        push(1)
        peekMax()
        popMax()
        push(763)
        popMax()
        Expected
        [430,234,234,-293,-443,349,1,1,763]
        Error
        Segmentation fault
