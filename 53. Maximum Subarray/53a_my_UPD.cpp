class Solution {

public:
  int maxSubArray(const vector<int>& a) {
    
    int CurrentMaxSuffixSum = a[0];
    int MaxSuffixSum = a[0];
    
    for (size_t i = 1; i < a.size(); i++) {
     CurrentMaxSuffixSum = max(CurrentMaxSuffixSum + a[i], a[i]);
     MaxSuffixSum = max(MaxSuffixSum, CurrentMaxSuffixSum);
    }
    
    return MaxSuffixSum;
    
  }
};
