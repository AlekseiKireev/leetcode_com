class RandomizedSet {

    unordered_map<int, int> valToPos; // [val] -> pos in 'values' vector 

    vector<int> values; // list of valToPos keys

    mt19937 gen;

public:

    /*- Initialize your data structure here. */
    RandomizedSet() : gen(2131), values(1, 0) {}


    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. 
    element.*/
        bool insert(int val) {
        int& pos = valToPos[val];
        if (pos != 0) {
            return false;
        }
        pos = (int)values.size();
        values.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = valToPos.find(val);
        if (it == valToPos.end()) {
            return false;
        }
        int pos = it->second;
        if (pos != (int)values.size() - 1) {
            int val2 = values.back();
            valToPos[val2] = pos;
            values[pos] = val2;
        }
        values.pop_back();
        valToPos.erase(it);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return values[uniform_int_distribution<int>(1, (int)values.size() - 1)(gen)];
    }

};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
