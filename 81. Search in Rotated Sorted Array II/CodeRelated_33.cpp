class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
      const int m = (l + r) / 2;
      
      if (nums[m] == target){return true;}

      // разница в условном операторе (в 33 он отсут-т) и возвращаемых значениях
      if (nums[l] == nums[m] && nums[m] == nums[r]) {
        ++l;
        --r;
      } else if (nums[l] <= nums[m]) {  // nums[l..m] are sorted
         (nums[l] <= target && target < nums[m]) ?
          r = m - 1
        :
          l = m + 1;
      } else {  // // nums[m..r] are sorted
        if (nums[m] < target && target <= nums[r]){
          if (nums[r] == target){return true;}
          l = m + 1;
        }
        else
          r = m - 1;
      }
    }

    return false;
  }
};
