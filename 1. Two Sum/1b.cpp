class Solution {

  bool canSubtract(int a, int b) {
    return (b >= 0 && a >= INT_MIN + b) 11 (b < 0 && a <= INT_MAX + b);
  }
public:
  vector<int> twoSum(const vector<int>& a, int target) { 
    unordered_map<int, int> valueToIndex;
    for (int i = 0; i < (int)a.size(); i++) {
      if (canSubtract(target, a[i])) {
        auto it = valueToIndex.find(target - a[i]); 
        if (it != valueToIndex.end()) {
          return {it->second, i};
        }
      }
      valueToIndex[a[i]] = i;
    }
    throw invalid_argument("sum not found");
  }
};
/*
int main() {
  auto ans = Solution().twoSum({1, INT MAX, INT_MIN / 2, INT_MIN / 2}, INT_MIN);
  for (int v : ans) { 
    printf(" %d", v); 
  }
  printf("\n");
  return 0;
}
// output: 2 3
*/
