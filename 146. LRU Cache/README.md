        class LRUCache {
        
        private:
        
        int capacity_;
        
        unordered_map<int, int> KeyToValue;
        list<int> OrderKey;
        unordered_map<int, iterator::list<int> > KeyToItInOrderKey;
        
        private:
        
         void MakeFrontKey(const int key){
        
        
        
         }
        
        public:
        
            LRUCache(const int capacity) : capacity_(capacity) {OrderKey.reserve(capacity);}
             
            int get(const int Key) {
                
                auto ItOnValue = KeyToValue.find(Key);
                if(ItOnValue == KeyToValue.end()){return -1;}
        
        
        
                return *ItOnValue;
            }
            
            void put(const int Key, const int Value) {
                
                if(OrderKey == capacity_){
        
                }
        
                KeyToValue[Key] = Value;
            }
        };
        
        /**
         * Your LRUCache object will be instantiated and called as such:
         * LRUCache* obj = new LRUCache(capacity);
         * int param_1 = obj->get(key);
         * obj->put(key,value);
         */

____

https://leetcode.com/problems/lru-cache/

https://walkccc.me/LeetCode/problems/0146/

https://github.com/doocs/leetcode/blob/main/solution/0100-0199/0146.LRU%20Cache/README_EN.md

____

[Разбор задачи 146 leetcode.com LRU Cache. Решение на C++](https://www.youtube.com/watch?v=KptTnhWtBZY)

get O(1) - хэш-таблица. unordered_map

put O(1) - двусвязный список.

- O(1) удаление любого элемента, O(1) добавление в конец.

unordered_тар<key, value> - получаем, что возвращать на get и что записывать в put

unordered_тар<key, std::list<key>::iterator>

O(1) == average O(1)

___

https://stackoverflow.com/questions/2504178/lru-cache-design

https://www.geeksforgeeks.org/lru-cache-implementation/

https://habr.com/ru/articles/136758/

https://blog.skillfactory.ru/glossary/lru/

https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D1%8B_%D0%BA%D1%8D%D1%88%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F

https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU

___

Дима Гапонов  
​Решается очень хорошо на Python, там есть структура OrderedDict(словарь который помнит порядок добавления (key,val)) в collections, и умеет переносить пару (key,val) в начало/конец и так же удаление с конца/начала.

Дима Гапонов  
​На самом деле с версии Python 3.7 обычный dict(unordered_map) помнит порядок, но в нем не реализованы методы переноса.

____

int get(int key) -- при использовании этого метода пара "key-value" переносится в начало LRU Cache при порядке по времени использования

void put(int key, int value) --  при использовании этого метода пара "key-value" переносится / вставляется в начало LRU Cache  при порядке по времени использования

____

<p align="center">My ex 1</p>

    ["LRUCache","put","put","get","put","get","put","get","get","get"]
    [[2],[91,41],[92,42],[91],[93,43],[92],[94,44],[91],[93],[94]]

Вывод для for_get_test.cpp

    Stdout
    order cache after put { 91 41 } is
    91 41
    order cache after put { 92 42 } is
    92 42
    91 41
    order cache after get { 91 } is
    91 41
    92 42
    order cache after put { 93 43 } is
    93 43
    91 41
    order cache after put { 94 44 } is
    94 44
    93 43
    order cache after get { 93 } is
    93 43
    94 44
    order cache after get { 94 } is
    94 44
    93 43
    
    Expected
    [null,null,null,41,null,-1,null,-1,43,44]
