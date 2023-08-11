class Solution {
public:
  int subarraySum(const vector<int>& nums, int k) {

    unordered_map<int, int> prefixSumToCount;
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

