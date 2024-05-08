class Solution {
public:
  int maxProfit(const vector<int>& a) { 
    int ans = 0;
    int prevMin = INT_MAX; // 10e4 + 1 подойдет == локальный максимум
    for (int v : a) {
      ans = max(ans, v - prevMin); 
      prevMin = min(prevMin, v);
    }
    return ans;
  }
};
