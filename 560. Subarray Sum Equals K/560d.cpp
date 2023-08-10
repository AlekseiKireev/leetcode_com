const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

class Solution {
public:

  int subarraySum(const vector<int>& nums, int k) { 

   map<int, int> prefixSumToCount;
   int prefixSum = 0;
   prefixSumToCount[prefixSum] = 1;

   int ans = 0;
   for (int v : nums) {
     prefixSum += v;
     auto it = prefixSumToCount.find(prefixSum - k);
     if (it != prefixSumToCount.end()) {ans += it->second;}
     prefixSumToCount[prefixSum]++;
   }

   return ans;

  }

};

