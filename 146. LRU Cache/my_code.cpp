// https://leetcode.com/problems/lru-cache/solutions/792449/simple-c-solution-with-detailed-explanation/  
// https://en.cppreference.com/w/cpp/container/list/splice

struct DataLRU{

    int key;
    int value;

};


class LRUCache{

private:

    list<DataLRU> order; // хранит порядок ключ-значение
    unordered_map<int, list<DataLRU>::iterator> keyToIterator; 
    int capacity;

public:


    LRUCache(int capacity) : capacity(capacity){}


    int get(int key){

        if (keyToIterator.find(key) == keyToIterator.end()) { return -1; }

        if (keyToIterator[key] != order.begin()) {
            order.splice(order.begin(), order, keyToIterator[key]); 
        }

        return keyToIterator[key]->value;
    }


    void put(int key, int value){

        if (keyToIterator.find(key) != keyToIterator.end()){

            order.splice(order.begin(), order, keyToIterator[key]);
            keyToIterator[key]->value = value;
            return;
        }

        if (order.size() == capacity){

            const auto delete_key = order.back().key;
            order.pop_back();
            keyToIterator.erase(delete_key);
        }

        order.push_front({ key,value });
        keyToIterator[key] = order.begin();
    }

};
