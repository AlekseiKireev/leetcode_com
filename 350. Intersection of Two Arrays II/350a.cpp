class Solution {

public:

   vector<int> intersect(const vector<int>& aa, const vector<int>& bb) { 

      // создание инварианта необходимо для оптимизации по памяти 
     const vector<int> &a = aa.size() < bb.size() ? aa : bb;
     const vector<int> &b = aa.size() < bb.size() ? bb : aa; 
     
      assert(a.size() <= b.size()); 
      
     unordered_map<int,int> count;
     for (int v : a) {count[v]++;}
     
     vector<int> ans;
     
     for (int v : b) {
        auto it = count.find(v);
        if (it != count.end() && it->second > 0) {
          ans.push_back(v);
          it->second--;
        }
     }
     
     return ans;
   }

};

/*
class Solution {
public:
    vector<int> intersect(vector<int>& ArrayMinSize, vector<int>& ArrayMaxSize) {
        
        if(ArrayMinSize.size() > ArrayMaxSize.size()){ // создание инварианта необходимо для оптимизации по памяти 
            return intersect(ArrayMaxSize, ArrayMinSize);
        }
      
        assert(ArrayMinSize.size() <= ArrayMaxSize.size()); 
         
        unordered_map<int, long long> NumToCount;

        for(int num : ArrayMinSize){++NumToCount[num];}
        
        vector<int> ArrayIntersection;
        for(int num : ArrayMaxSize){
            
            if(NumToCount[num]-- > 0){
                ArrayIntersection.push_back(num); // "return the result in any order"
            }
        }

        return ArrayIntersection;
    }
};
*/
