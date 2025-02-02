class Solution {
public:
  bool checkSubarraySum(const vector<int>& a, int k) { 

     unordered_set<int> ExistPS; 
     long long CurrentSum = 0;
     for (int v : a) {
       int prevSum = CurrentSum; 
       
       CurrentSum = (CurrentSum + k + v % k) % k; 
       if (ExistPS.count(CurrentSum)) {return true;}
       ExistPS.insert(prevSum);
       
     }
     
     return false;
  }
} ;
