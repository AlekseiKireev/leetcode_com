#include <iostream>
#include <vector>
#include <queue>
#include <variant>
using namespace std;

// Mock implementation of the NestedInteger class
class NestedInteger {
private:
    variant<int, vector<NestedInteger>> data;

public:
    // Constructor for single integer
    NestedInteger(int value) : data(value) {}

    // Constructor for a nested list
    NestedInteger(vector<NestedInteger> nestedList) : data(nestedList) {}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
        return holds_alternative<int>(data);
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        if (isInteger()) {
            return get<int>(data);
        }
        throw runtime_error("This NestedInteger holds a nested list.");
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const {
        if (!isInteger()) {
            return get<vector<NestedInteger>>(data);
        }
        throw runtime_error("This NestedInteger holds a single integer.");
    }
};

// NestedIterator implementation
class NestedIterator {
private:
    queue<int> FlattenList;

    void Travel(const vector<NestedInteger>& nestedList) {
        for (const auto& NI : nestedList) {
            if (NI.isInteger()) {
                FlattenList.push(NI.getInteger());
            } else {
                Travel(NI.getList());
            }
        }
    }

public:
    NestedIterator(const vector<NestedInteger>& nestedList) {
        Travel(nestedList);
    }

    int next() {
        int val = FlattenList.front();
        FlattenList.pop();
        return val;
    }

    bool hasNext() {
        return !FlattenList.empty();
    }
};

// Function main to demonstrate the usage of NestedIterator
int main() {
    // Creating a nested list for testing
    vector<NestedInteger> nestedList = {
        NestedInteger(1),
        NestedInteger(vector<NestedInteger>{
            NestedInteger(2),
            NestedInteger(vector<NestedInteger>{
                NestedInteger(3),
                NestedInteger(4)
            })
        }),
        NestedInteger(5)
    };

    // Create the iterator
    NestedIterator i(nestedList);

    // Use the iterator to print all integers
    while (i.hasNext()) {
        cout << i.next() << " ";
    }
    // Output should be: 1 2 3 4 5

    return 0;
}
