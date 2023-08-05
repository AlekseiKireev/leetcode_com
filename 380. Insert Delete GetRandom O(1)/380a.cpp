class RandomizedSet {

    unordered_map<int, int> valToPos; // [val] -> pos in 'values' vector 

    vector<int> values; // list of valToPos keys

    mt19937 gen;

public:

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
       if (valToPos.count(val) > 0) {
           return false;
       }

       valToPos[val] = (int)values.size();
       values.push_back(val);
       return true;

    }

    // примемчательно то, что работает верно для последнего элемента, т.е. когда pos = values.size() - 1 --> val == val2
    /* * Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
       if (valToPos.count(val) == 0) {
           return false;
       }

       int pos = valToPos[val]; 
       int val2 = values.back(); 
       valToPos[val2] = pos; 
       values[pos] = val2;
       valToPos.erase(val);
       values.pop_back();
       return true;

    }

    /* * Get a random element from the set. */
    int getRandom() {
       return values[uniform_int_distribution<int>(0, (int)values.size() - 1)(gen)];
    }
} ;


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
