class Solution {
public:
  vector<int> twoSum(const vector<int>& a, int target) { 
    unordered_map<int, int> valueToIndex;
    for (int i = 0; i < (int)a.size(); i++) {
      auto it = valueToIndex.find(target - a[i]); 
      if (it != valueToIndex.end()) {
        return {it->second, i};
      }
      valueToIndex[a[i]] = i;
    }
    throw invalid_argument("sum not found");
  }
};
