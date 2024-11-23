class LRUCache {

const int capacity_;

unordered_map<int, list<int>::iterator> KeyToItInOrderKey;
list<int> OrderKey;
unordered_map<int, int> KeyToValue;

void Up(int key){

        OrderKey.erase(KeyToItInOrderKey[key]);
        OrderKey.push_front(key);
        KeyToItInOrderKey[key] = OrderKey.begin();
}

public:

    LRUCache(int capacity) : capacity_(capacity) {

    }
    
    int get(int key) {
        
        if(KeyToValue.count(key) == 0){
            return -1;
        }

        Up(key);
        return KeyToValue[key];
    }
    
    void put(int key, int value) {
        
        
        if(KeyToValue.count(key) == 0){
            
            OrderKey.push_front(key);
            KeyToItInOrderKey[key] = OrderKey.begin();
        }
        else{
            Up(key);
        }
        KeyToValue[key] = value;

        
        if(capacity_ + 1 == OrderKey.size()){
            int B = OrderKey.back();
            
            OrderKey.pop_back();
            KeyToItInOrderKey.erase(B);
            KeyToValue.erase(B);
        }
    }

};
