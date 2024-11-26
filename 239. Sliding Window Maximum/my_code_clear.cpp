/*
Time complexity : O(n)
Space complexity : O(n)
*/   
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
    vector<int> result;        
    result.reserve(nums.size() + 1 - k);
    deque<int> windowIndices;  

    for (int i = 0; i < nums.size(); ++i) {

      while (!windowIndices.empty() && nums[windowIndices.back()] <= nums[i]) { 
        windowIndices.pop_back();
      }

      windowIndices.push_back(i);


      if (windowIndices.front() < i - k + 1) { 
        windowIndices.pop_front();
      }

      if (i - k + 1 >= 0) { 
        result.push_back(nums[windowIndices.front()]); 
      }
      
    }

    return result;
  }
};
