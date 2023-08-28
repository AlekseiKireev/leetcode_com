// https://walkccc.me/LeetCode/problems/0341/ == Approach 1: Recursive (Queue)

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
 public:
  NestedIterator(vector<NestedInteger>& nestedList) {
    addInteger(nestedList);
  }

  int next() {
    const int num = q.front();
    q.pop();
    return num;
  }

  bool hasNext() {
    return !q.empty();
  }

 private:
  queue<int> q;

  void addInteger(const vector<NestedInteger>& nestedList) {

    for (const NestedInteger& ni : nestedList)
      if (ni.isInteger()){
          cout << "isInteger\n";
          q.push(ni.getInteger());
      }
      else{
          cout << "Not isInteger\n";
          addInteger(ni.getList());
      }
  }

};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

/*
Input [1,1,2,1,1]

Stdout
isInteger
isInteger
isInteger
isInteger
isInteger

Output
[1,1,2,1,1]
Expected
[1,1,2,1,1]
*/

/*
Input [[1],[1],[2],[1],[1]]

Stdout
Not isInteger
isInteger
Not isInteger
isInteger
Not isInteger
isInteger
Not isInteger
isInteger
Not isInteger
isInteger

Output
[1,1,2,1,1]
Expected
[1,1,2,1,1]
*/

/*
Input
[1, [2, [3, [4, [5]]]]]
Stdout
isInteger
Not isInteger
isInteger
Not isInteger
isInteger
Not isInteger
isInteger
Not isInteger
isInteger
View less 
Output
[1,2,3,4,5]
Expected
[1,2,3,4,5]
*/
