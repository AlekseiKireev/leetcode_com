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
/*
Time complexity: O(n)
Space complexity: O(n)
*/
class NestedIterator {

private:

queue <int> FlattenList;

void Travel(const vector<NestedInteger> &nestedList){

      for(const auto& NI : nestedList){ // "Each element nestedList is either an integer or a list whose elements may also be integers or other lists."
          if(NI.isInteger()){
            FlattenList.push(NI.getInteger());

          }else{ // getList для того, чтобы скастовать NestedInteger к vector<NestedInteger>
            Travel(NI.getList());
          }

      }

}

public:

    NestedIterator(const vector<NestedInteger> &nestedList) {
      
      Travel(nestedList);

        // error!
        /*
      for(const auto& NI : nestedList){
          if(NI.isInteger()){
            FlattenList.push(NI.getInteger());

          }else{
            NestedIterator(NI.getList()); // error!
          }

      }
        */
    
    }
    
    int next() {
        const int val = FlattenList.front();
        FlattenList.pop();
        return val;
    }
    
    bool hasNext() {
        return !FlattenList.empty();
    }

};

/*

А Б, [8/28/2023 9:26 PM]
условие: https://leetcode.com/problems/flatten-nested-list-iterator/description/

мой код: https://pastebin.com/PLQvZK8H

вопрос:  почему это решение падает на первом тесте, в то время как если метод NestedIterator(const vector<NestedInteger> &nestedList) { ...

исправить на

    NestedIterator(const vector<NestedInteger> &nestedList) {
      
      Travel(nestedList);
    }

все работает

Yuriy, [8/28/2023 9:39 PM]
Конструктор NestedIterator в L50 создаёт другой объект, с другим FlattenList (и сразу же его уничтожает)

*/
