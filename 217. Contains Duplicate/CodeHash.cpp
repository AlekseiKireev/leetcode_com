  class Solution {
  public:
      bool containsDuplicate(vector<int>& nums) {
          unordered_map<int,int> NumToCount;
          for(auto num : nums) {NumToCount[num]++;}
          
          for(auto [Num, Count] : NumToCount){
              if(Count >= 2) {return true;}
          }
          return false;
      }
  };
