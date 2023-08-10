class Solution {
public:
  int subarraySum(const vector<int>& nums, int k) {

    unordered_map<int, int> prefixSumToCount;
    int prefixSum = 0;
    prefixSumToCount[prefixSum] = 1;

    int ans = 0;
    for (int v : nums) {
      prefixSum += v;
      ans += prefixSumToCount[prefixSum - k]; // из существ-я prefixSum - k --> существ-е префикса prefixSum_k, т.е. prefixSum - prefixSum_k = k <--> prefixSum_k = prefixSum - k
      prefixSumToCount[prefixSum]++;
    }

    return ans;
  }

};

