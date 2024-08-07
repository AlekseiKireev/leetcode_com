  class Solution {
  public:
      bool containsDuplicate(vector<int>& nums) {
          
          ranges::sort(nums);
          
          for(int i = 0; i + 1< nums.size(); ++i){

            if(nums[i] == nums[i+1]){return true;}
            
          }

          return false;
      }
  };
