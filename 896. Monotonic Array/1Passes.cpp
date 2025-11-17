class Solution {
 public:
  bool isMonotonic(vector<int>& nums) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < nums.size(); ++i) {
      increasing &= nums[i] >= nums[i - 1]; // Если есть убывание, то возрастающая монотонность нарушена
      decreasing &= nums[i] <= nums[i - 1]; // Если есть возрастание, то убывающая монотонность нарушена
     // добавить выход, когда оба условия не выполняются
    }

    return increasing || decreasing;
  }
};
