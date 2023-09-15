class Solution {
public:
  vector<int> searchRange(const vector<int>& a, int target) {
    auto first = lower_bound(a.begin(), a.end(), target); 
    if (first == a.end() || *first != target) {
      return {-1, -1};
    }
    auto after = upper_bound(a.begin(), a.end(), target);
    return {int(first - a.begin()), int(after - a.begin() - 1)};
  }
};
