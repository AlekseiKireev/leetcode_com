class Solution {
public:
  bool checkSubarraySum(const vector<int>& a, int k) { 

   
    /*
    if(a.size() > k){return true;} // принцип Дирихле. По сути, это бы стработало, если a[j] > 0 
    // error: 96 / 98 testcases passed
    // nums = [1,0,1,0,1]
    // k = 4
    */

     unordered_set<int> seen;
     int sum = 0;
     for (int v : a) {
       int prevSum = sum;
       sum += v; 
       sum %= k; 
       
       if (seen.count(sum)) { // на момент проверки существования sum в seen, в seen еще не лежит prevSum --> на момент проверки sum[i] в seen = {sum[0], ..., sum[i - 2]} : i >= 2
         return true;
       }

       seen. insert(prevSum);
     }
     
     return false;
  }
} ;
