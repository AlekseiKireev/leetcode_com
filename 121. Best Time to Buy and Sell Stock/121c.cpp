class Solution {
public:
  int maxProfit(const vector<int>& a) {
    int ans = 0;
    int nextMax = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) { 
      int v = a[i];
      ans = max(ans, nextMax - v);
      nextMax = max(nextMax, v);
    }
    return ans;
  }
};
/*
class Solution {
public:
  int maxProfit(const vector<int>& a) {
    int ans = 0;
    int nextMax = 0;
    for (size_t i = a.size() ; i-- > 0; i) { 
      int v = a[i];
      ans = max(ans, nextMax - v);
      nextMax = max(nextMax, v);
    }
    return ans;
  }
};
*/
