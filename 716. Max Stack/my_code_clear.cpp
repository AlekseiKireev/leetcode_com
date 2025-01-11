class MaxStack {

list<int> OrderVal;
map< int, vector<list<int>::iterator>, greater<int> > ValToItsOnVal;

public:

    MaxStack() {
    }

    void push(int x) {
        OrderVal.push_front(x); 
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
