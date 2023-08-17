/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {

    struct ListPos {

        const vector<NestedInteger>* list;
        int nextPos;
    };


    stack<ListPos> positions;

    int cur;

    bool curFilled;

    void fillCur() {

        if (curFilled) { return; }

        while (true) {
            if (positions.empty()) {
                return;
            }

            const vector<NestedInteger>& list = *positions.top().list;
            int& nextPos = positions.top().nextPos;
          
            if (nextPos >= (int)list.size()) {
                positions.pop();
                continue;
            }
          
            if (list[nextPos].isInteger()) {
                cur = list[nextPos].getInteger();
                curFilled = true;
                nextPos++;
                return;
            }
          
            nextPos++;
            positions.push(ListPos{ &list[nextPos - 1].getList(), 0 });
        }
    }


public:

    NestedIterator(const vector<NestedInteger>& nestedList)
        : cur(0)
        , curFilled(false)
    {
        positions.push(ListPos{ &nestedList, 0 });
    }


    int next() {
        fillCur();
        if (curFilled) {
            curFilled = false;
            return cur;
        }
        else {
            throw logic_error("next() called when hasNext() false");
        }
    }


    bool hasNext() {
        fillCur();
        return curFilled;
    }

};



/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
