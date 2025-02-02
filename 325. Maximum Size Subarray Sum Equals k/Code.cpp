class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    int ans = 0;
    int prefix = 0;
    unordered_map<int, int> PSumToIdxPSum{{0, 0}};

    for (int i = 0; i < nums.size(); ++i) {
        
      prefix += nums[i];
    
    // обновление ответа
      const int target = prefix - k;
      if (PSumToIdxPSum.count(target) == 1){
        // "+1" обусловлен тем, что индекс префиксной суммы на +1 больше
        ans = max(ans, i + 1 - PSumToIdxPSum[target]);
      }

        // обновляем только один раз, чтобы зафиксировать левую границу -->         
        // более длинное окно, т.к. Right-Left --> max if Left --> min
      if (PSumToIdxPSum.count(prefix) == 0){ 
         // "+1" обусловлен тем, что индекс префиксной суммы на +1 больше
        PSumToIdxPSum[prefix] = i + 1;  
      }
        
    }

    return ans;
  }
};
