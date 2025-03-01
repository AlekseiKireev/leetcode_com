class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    int prefix = 0;

    for (int i = 0; i < nums.size(); ++i) {
        
      if (prefix == sum - prefix - nums[i]){ // nums = [2,1,-1]
        return i;
      }
      // из nums = [2,1,-1] следует, что обновлять prefix стоит после оброботки ответа  
      prefix += nums[i];
    }

    return -1;
  }
};
