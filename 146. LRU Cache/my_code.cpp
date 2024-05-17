// https://leetcode.com/problems/lru-cache/solutions/792449/simple-c-solution-with-detailed-explanation/  
// https://en.cppreference.com/w/cpp/container/list/splice

    class LRUCache {
    
    private:
    
    const int capacity_;
    
    unordered_map<int, int> KeyToValue; // <-- "The functions get and put must each run in O(1) average time complexity."
    list<int> OrderKey;
    unordered_map<int, list<int>::iterator > KeyToItInOrderKey; // <-- "The functions get and put must each run in O(1) average time complexity."
    
    private:
    
    // Используется, если {Key, Value} уже существует в KeyToValue
     void MoveFrontKey(const int Key){

        // https://en.cppreference.com/w/cpp/container/list/splice
        // "Transfers the element pointed to by it from other into *this. The element is inserted before the element pointed to by pos."
        OrderKey.splice(OrderKey.begin(),OrderKey, KeyToItInOrderKey[Key]);
        KeyToItInOrderKey[Key] = OrderKey.begin();    
    
     }
    
    public:
    
        LRUCache(const int capacity) : capacity_(capacity) {}
         
        int get(const int Key) {
            
            auto ItOnValue = KeyToValue.find(Key);
            if(ItOnValue == KeyToValue.end()){return -1;}

            // if(It != KeyToValue.begin()){MoveFront(key);} // equiv
            if(OrderKey.front() != Key){
                MoveFrontKey(Key);
            }

    
            return ItOnValue->second;
        }
        
        void put(const int Key, const int Value) {
            
            auto ItOnValue = KeyToValue.find(Key);
            if(ItOnValue != KeyToValue.end()){ // "Update the value of the key if the key exists. "
                
                KeyToValue[Key] = Value;
                MoveFrontKey(Key);
                return;
            } // " Otherwise, add the key-value pair to the cache. "           

            assert(ItOnValue == KeyToValue.end());
            KeyToValue[Key] = Value;
            OrderKey.push_front(Key);
            KeyToItInOrderKey[Key] = OrderKey.begin();

            if(OrderKey.size() == capacity_ + 1){ // "If the number of keys exceeds the capacity from this operation, evict the least recently used key."
                
                KeyToValue.erase(OrderKey.back());
                KeyToItInOrderKey.erase(OrderKey.back());
                OrderKey.pop_back();
            }
    
            
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */
