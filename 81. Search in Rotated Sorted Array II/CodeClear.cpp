class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
      const int m = l + (r - l) / 2;

      if (nums[m] == target)
        return true;

      // Удаляем дублирующиеся элементы на границах
      for (; l < m && nums[l] == nums[m]; ++l);
        
      for (; r > m && nums[r] == nums[m]; --r);
        

      if (nums[l] <= nums[m]) {  // nums[l..m] отсортирован
        (nums[l] <= target && target < nums[m]) ? r = m - 1 : l = m + 1;
      } else {  // nums[m..r] отсортирован
        (nums[m] < target && target <= nums[r]) ? l = m + 1 : r = m - 1;
      }
    }

    return false;
  }
};
