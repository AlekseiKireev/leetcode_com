class NestedIterator {

queue<int> QueueVal;

void Travel(vector<NestedInteger> &nestedList){

    for(auto nL : nestedList){
        if(nL.isInteger()){
            QueueVal.push(nL.getInteger());
        }else{
            Travel(nL.getList());
        }
    }
}

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        Travel(nestedList);
    }
    
    int next() {

        int x = QueueVal.front();
        QueueVal.pop();
        return x;
    }
    
    bool hasNext() {
        return !QueueVal.empty();
    }
};
