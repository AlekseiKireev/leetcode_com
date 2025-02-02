class Solution {
public:
  bool checkSubarraySum(const vector<int>& a, int k) { 

     unordered_set<int> ExistPS; // == {PS[0], ..., PS[i - 2]}
     int CurrentSum = 0;
     for (int v : a) {
       int prevSum = CurrentSum; // == PS[i-1]
       CurrentSum += v; // == PS[i]
       CurrentSum %= k; 
       
        // на момент проверки существования sum в ExistPS, в ExistPS еще не лежит prevSum и CurrentSum --> 
        //  на момент проверки sum[i] в ExistPS = {sum[0], ..., sum[i - 2]} : i >= 2
       if (ExistPS.count(CurrentSum)) {return true;}

       ExistPS. insert(prevSum);
     }
     
     return false;
  }
};
