class RandomizedSet {

private:

unordered_set<int> Values;

public:
    
    bool insert(int val) {

        if(Values.count(val) == 1){return false;}
        Values.insert(val);
        return true;

    }
    
    bool remove(int val) {
        
        if(Values.count(val) == 0){return false;}
        Values.erase(val);
        return true;
        
    }
    
    int getRandom() const { // "There will be at least one element in the data structure when getRandom is called."

        return *next(Values.cbegin(), rand() % Values.size() );
        
    }
};
