class RandomizedSet {

private:

unordered_map<int, int> ValToPos;
vector<int> Values;

public:
    
    bool insert(int val) {
        
        if(ValToPos.count(val) == 1){return false;} // "Returns true if the item was not present, false otherwise."
        
        ValToPos[val] = Values.size();
        Values.push_back(val);

        return true;

    }
    
    bool remove(int val) {

        if(ValToPos.count(val) == 0){return false;} // "Returns true if the item was present, false otherwise."
        
        Values[ValToPos[val]] = Values.back(); // удаление через перезаписывание 
        ValToPos[ Values.back() ] = ValToPos[val]; // как видно из предыдущей строки, элемень Values.back() находится по индексу ValToPos[val], поэтому надо ValToPos : Values.back() --> ValToPos[val]

        Values.pop_back();
        ValToPos.erase(val);

        return true;

    }
    
    int getRandom() const { // "There will be at least one element in the data structure when getRandom is called."
        // "Each element must have the same probability of being returned."
        return Values.at(rand() % Values.size());

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
