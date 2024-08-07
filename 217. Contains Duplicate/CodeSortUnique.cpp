  class Solution {
  public:
      bool containsDuplicate(vector<int>& nums) {
          
          ranges::sort(nums);
          auto last = std::unique(nums.begin(), nums.end());
          return last != nums.end();
      }
  };
