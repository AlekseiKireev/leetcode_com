class Solution {
public:
  int subarraySum(const vector<int>& nums, int k) {

    unordered_map<int, int> prefixSumToCount; // ввиду формул в README не префикс, а аффикс
    int prefixSum = 0;
    prefixSumToCount[prefixSum] = 1; // для обработки случая prefixSum = k 

    int ans = 0;
    for (int v : nums) {
      prefixSum += v;
      ans += prefixSumToCount[prefixSum - k];
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
