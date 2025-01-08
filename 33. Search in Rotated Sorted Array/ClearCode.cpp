class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (0 != r - l + 1) { // <--> l <= r
      const int m = (l + r) / 2;
      
      if (nums[m] == target){return m;}
        
      if (nums[l] <= nums[m]) {  // nums[l..m] are sorted
            (nums[l] <= target && target < nums[m]) ? r = m - 1 : l = m + 1;
      } else {  // nums[m..r] are sorted
            (nums[m] < target && target <= nums[r]) ? l = m + 1 : r = m - 1;
      }
    }

    return -1;
  }
};
