/*
class ZigzagIterator {
 public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {

  }

  int next() {

  }

  bool hasNext() {
    
  }
};
*/

class ZigzagIterator {

private:

struct Pair{
    
    const vector<int>::iterator CurrentItr;
    const vector<int>::iterator EndItr;
    
};

private:

    queue<Pair> GetZigzag;

public:
    ZigzagIterator(const vector<int>& v1, const vector<int>& v2) { // 0 <= v1.length, v2.length <= 1000        
        
        if(v1.empty() == false){GetZigzag.push({v1.cbegin(), v1.cend()});}
        if(v2.empty() == false){GetZigzag.push({v2.cbegin(), v2.cend()});}
        
    }

    int next() {
        
        
        const auto CurItr = 
        return ;
    }

    bool hasNext() { return !(GetZigzag.empty()); }
    
}; 
       
