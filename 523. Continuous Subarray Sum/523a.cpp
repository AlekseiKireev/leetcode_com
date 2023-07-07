class Solution {
public:
  bool checkSubarraySum(const vector<int>& a, int k) { 

     if (k == 0) {
       for (int i = 1; i < (int)a.size(); i++) {
          if (a[i] == 0 && a[i - 1] == 0) {return true;}
       }
       return false;
     }

     assert(k != 0); 
     unordered_set<int> seen;
     int sum = 0;
     for (int v : a) {
       int prevSum = sum;
       sum += v; 
       sum %= k; 
       
       if (seen.count(sum)) {return true;}

       seen. insert(prevSum);
     }
     return false;
  }
};
