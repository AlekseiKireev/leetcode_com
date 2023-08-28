class Solution {
public:
  int maxSubArray(const vector<int>& a) {
    
    int maxEndsHere = a[0];
    int totalMax = a[0];
    
    for (size_t i = 1; i < a.size(); i++) {
     maxEndsHere = max(maxEndsHere + a[i], a[i]);
     totalMax = max(totalMax, maxEndsHere);
    }
    
    return totalMax;
    
  }
};

