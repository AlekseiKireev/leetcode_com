class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

    set<int> window;

    for (int i = 0; i < nums.size(); ++i) {

        auto it =  window.lower_bound(nums[i] - valueDiff); // *it >= nums[i] - valueDiff
        if (
         it != window.end() 
         && 
         *it - nums[i] <= valueDiff /* Check: abs(nums[i] - nums[j]) <= valueDiff*/
        ){
        return true;
        }

        window.insert(nums[i]);

        /* Check: abs(i - j) <= indexDiff */
        if (window.size() > indexDiff){ // на каждой итерации гаранти-о удаляется элемент вне окна
           window.erase(nums[i - indexDiff]);
        }


    }

    return false;
  }
};
