class RandomizedSet {

    unordered_set<int> values;

public:
    
    bool insert(int val) {
        if (values.count(val) == 1) { return false; }
        values.insert(val);
        return true;
    }

    bool remove(int val) {
        if (values.count(val) == 0) { return false; }
        values.erase(val);
        return true;
    }

    int getRandom() { // "There will be at least one element in the data structure when getRandom is called."
         return *next(values.begin(),  rand() % values.size()); // https://en.cppreference.com/w/cpp/iterator/next
    }
};
