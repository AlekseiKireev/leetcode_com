/*

В любой момент времени размер window не превышает indexDiff (то есть k).
Значит, поиск и вставка происходят в балансированном дереве с k элементами

Time:O(nlog⁡(indexDiff)) 
Space:O(indexDiff)
*/
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

    multiset<int> window;

    for (int i = 0; i < nums.size(); ++i) {

      // необходим с целью минимизировать разницу nums[i] - nums[j] --> valueDiff
      auto it = window.lower_bound(nums[i] - valueDiff); // *it >= nums[i] - valueDiff
     
      if (it != window.end() && *it - nums[i] <= valueDiff) { /* Check: abs(nums[i] - nums[j]) <= valueDiff*/
        return true;
      }

      window.insert(nums[i]);
    
      /* Check: abs(i - j) <= indexDiff */
      if (window.size() > indexDiff) { // на каждой итерации гаранти-о удаляется элемент вне окна
        window.erase(window.find(nums[i - indexDiff])); // Удаляем только ОДНО вхождение!
      }
    }

    return false;
  }
};
