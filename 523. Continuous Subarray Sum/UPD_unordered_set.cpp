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

       // seen. insert(prevSum); // error: nums = [1,2,12] k = 6 --> PS = [0,1,3,3] -- при таком положение находятся в том числе длинной 1
       // на момент проверки существования sum в seen, в seen еще не лежит prevSum --> на момент проверки sum[i] в seen = {sum[0], ..., sum[i - 2]} : i >= 2
       if (seen.count(sum)) {return true;}

       seen. insert(prevSum); // "its length is at least two"
     }
     
     return false;
  }
} ;
/*
class Solution {
public:
  bool checkSubarraySum(const vector<int>& a, int k) { 

     unordered_set<int> seen;
     int CurrentSum = 0;
     for (int v : a) {
       int prevSum = CurrentSum; // == sum[i-1]
       CurrentSum += v; // == sum[i]
       CurrentSum %= k; 
       
        // на момент проверки существования sum в seen, в seen еще не лежит prevSum и CurrentSum --> 
        //  на момент проверки sum[i] в seen = {sum[0], ..., sum[i - 2]} : i >= 2
       if (seen.count(CurrentSum)) {return true;}

       seen. insert(prevSum);
     }
     
     return false;
  }
} ;
*/
