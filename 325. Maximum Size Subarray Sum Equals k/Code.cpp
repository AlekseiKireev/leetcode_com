class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    int ans = 0;
    int prefix = 0;
    unordered_map<int, int> prefixToIndex{{0, 0}};

    for (int i = 0; i < nums.size(); ++i) {
        
      prefix += nums[i];
    
    // обновление ответа
      const int target = prefix - k;
      if (prefixToIndex.count(target) == 1){
        // "+1" обусловлен тем, что индекс префиксной суммы на +1 больше
        ans = max(ans, i + 1 - prefixToIndex[target]);
      }

        // обновляем только один раз, чтобы зафиксировать левую границу -->         
        // более длинное окно, т.к. Right-Left --> max if Left --> min
      if (prefixToIndex.count(prefix) == 0){ 
         // "+1" обусловлен тем, что индекс префиксной суммы на +1 больше
        prefixToIndex[prefix] = i + 1;  
      }
        
    }

    return ans;
  }
};
