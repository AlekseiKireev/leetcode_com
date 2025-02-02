class Solution {
public:
  bool checkSubarraySum(const vector<int>& a, int k) { 

     unordered_set<int> seen; 
     long long CurrentSum = 0;
     for (int v : a) {
       int prevSum = CurrentSum; 
       
       CurrentSum = (CurrentSum + k + v % k) % k; 
       if (seen.count(CurrentSum)) {return true;}
       seen.insert(prevSum);
       
     }
     
     return false;
  }
} ;
