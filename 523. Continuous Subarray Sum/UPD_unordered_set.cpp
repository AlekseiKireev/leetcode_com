class Solution {
public:
  bool checkSubarraySum(const vector<int>& a, int k) { 

    // error: 96 / 98 testcases passed
    /*
    if(a.size() > k){return true;} // принцип Дирихле. По сути, это бы стработало, если a[j] > 0 
    nums = [1,0,1,0,1]
    k = 4
    */

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
} ;
