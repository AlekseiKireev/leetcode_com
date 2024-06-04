const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

class Solution {
public:

  int subarraySum(const vector<int>& nums, int k) { 

   unordered_map<int, int> prefixSumToCount;
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
/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int AffixOrPrefix) {
        
        unordered_map<int, int> PartToCount;
        int PrefixSum = 0;
        ++PartToCount[PrefixSum];

        int Ans = 0;

        for(int num : nums){

            PrefixSum += num;
            Ans += PartToCount[PrefixSum - AffixOrPrefix];
            ++PartToCount[PrefixSum];
            
        }

        return Ans;
    }
};
*/

