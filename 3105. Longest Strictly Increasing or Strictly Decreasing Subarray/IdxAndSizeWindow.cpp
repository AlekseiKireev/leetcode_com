class Solution {

  pair<int, int> FindIdxAndWindowForLMS(vector<int>& nums) {
    int ans = 1, startIndex = 0;
    int increasing = 1, decreasing = 1;
    int incStart = 0, decStart = 0;
    
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        increasing += 1;
        decreasing = 1;
        decStart = i;
      } else if (nums[i] < nums[i - 1]) {
        decreasing += 1;
        increasing = 1;
        incStart = i;
      } else {
        increasing = 1;
        decreasing = 1;
        incStart = decStart = i;
      }
      
      if (increasing > ans) {
        ans = increasing;
        startIndex = incStart;
      }
      if (decreasing > ans) {
        ans = decreasing;
        startIndex = decStart;
      }
      
    }
    
    return {ans, startIndex};
  }

public:
    int longestMonotonicSubarray(vector<int>& nums) {
        return FindIdxAndWindowForLMS(nums).first;
    }
};
