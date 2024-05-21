https://leetcode.com/problems/max-stack/description/ - closed

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

Так как popMax может быть из любого места стека, то удобно использовать list<type(x)> OrderVal и удалять по итератору 

Обсудим оптимальное удаление и "If there is more than one maximum element, only remove the top-most one."

Для максимума будем использовать RBT и брать крайний элемент

# Плохая идея: метка времени

multimap< {x, time}, list<type(x)>::iterator > ValToItList
unordered_map<x, time> ValToCount

в качестве временных меток будет количество, т.е. 1 <= time -- если time = 0, удалены все элементы x

# Хорошая идея: в ДРМ push_back располагаются в порядке возрастания времени

map<x, vector<list<type(x)>::iterator> > ValToItsList

# вместо RBT можно использовать очередь с приоритетом?
