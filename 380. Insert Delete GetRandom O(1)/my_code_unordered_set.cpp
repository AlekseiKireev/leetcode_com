class RandomizedSet {

private:

unordered_set<int> Values;

public:
    
    bool insert(int val) {

        if(Values.count(val)){return false;}
        Values.insert(val);
        return true;

    }
    
    bool remove(int val) {
        
        if(Values.count(val) == 0){return false;}
        Values.erase(val);
        return true;
        
    }
    
    int getRandom() const {

        return *next(Values.cbegin(), rand() % Values.size() );
        
    }
};
