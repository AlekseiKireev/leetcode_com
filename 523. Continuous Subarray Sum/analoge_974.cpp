class Solution {
public:
  bool checkSubarraySum(const vector<int>& a, int k) { 

     unordered_set<int> seen; // == {PS[0], ..., PS[i - 2]}
     long long CurrentSum = 0; // с типом int будет ошибка RE!
     for (int v : a) {
       int prevSum = CurrentSum; // == PS[i-1]
       
       /* // good!!
       CurrentSum += v; // == PS[i]
       CurrentSum %= k; 
        */
        /* более общая формула, которая следует из 
        https://github.com/SkosMartren/leetcode_com/tree/main/974.%20Subarray%20Sums%20Divisible%20by%20K
        имеет место быть на случай nums[i] < 0
        */
       CurrentSum = (CurrentSum + k + v % k) % k; 
       
        // на момент проверки существования sum в seen, в seen еще не лежит prevSum и CurrentSum --> 
        //  на момент проверки sum[i] в seen = {sum[0], ..., sum[i - 2]} : i >= 2
       if (seen.count(CurrentSum)) {return true;}

       seen. insert(prevSum);
     }
     
     return false;
  }
} ;
