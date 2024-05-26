#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <iterator>
#include <functional>

using namespace std;

class MaxStack {

list<int> OrderVal;
map< int, vector<list<int>::iterator>, greater<int> > ValToItsOnVal;
/* vector<list<int>::iterator> так как видно, что значения, в том числе максимальные, могут повторяться 
Input:
push(5)
push(1)
push(5)
top()
popMax()
top()
peekMax()
pop()
top()
Output:
5
5
1
5
1
5
*/
public:

    MaxStack() {
    }

    void push(int x) {
        OrderVal.push_front(x); // так будет легче обращаться к значению, лежащему на вершине стека
        ValToItsOnVal[x].push_back(OrderVal.begin());
    }

    int pop() {

        const int ValTopStack = OrderVal.front();
        auto& VCT = ValToItsOnVal[ValTopStack];

        VCT.pop_back();
        if(VCT.empty()){
            ValToItsOnVal.erase(ValTopStack);
        }

        OrderVal.pop_front();
        
        return ValTopStack;
    }

    int top() {
        return OrderVal.front();
    }

    int peekMax() {
        return ValToItsOnVal.begin()->first;
    }

    int popMax() {

        const int ValMax = peekMax();
        auto& VCT = ValToItsOnVal.begin()->second;
        
        OrderVal.erase(VCT.back());
        VCT.pop_back();

        if(VCT.empty()){
            ValToItsOnVal.erase(ValToItsOnVal.begin());
        }

        return ValMax;
    }

};

int main() {
    MaxStack stk;
    stk.push(5);   // [5] the top of the stack and the maximum number is 5.
    stk.push(1);   // [5, 1] the top of the stack is 1, but the maximum is 5.
    stk.push(5);   // [5, 1, 5] the top of the stack is 5, which is also the maximum, because it is the top most one.

    cout << stk.top() << '\n';     // return 5, [5, 1, 5] the stack did not change.
    cout << stk.popMax() << '\n';  // return 5, [5, 1] the stack is changed now, and the top is different from the max.
    cout << stk.top() << '\n';     // return 1, [5, 1] the stack did not change.
    cout << stk.peekMax() << '\n'; // return 5, [5, 1] the stack did not change.
    cout << stk.pop() << '\n';     // return 1, [5] the top of the stack and the max element is now 5.
    cout << stk.top() << '\n';     // return 5, [5] the stack did not change.

    return 0;
}
