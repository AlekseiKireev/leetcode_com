class Solution {
public:
  bool checkSubarraySum(const vector<int>& a, int k) { 
    if (k == 0) {
      for (int i = 1; i < (int)a.size(); i++) { 
       if (a[i] == 0 && a[i - 1] == 0) {
         return true;
       }
      }
      return false;
    }
    assert(k != 0);

    unordered_map<int, int> firstPos; // [sum % k] -> lastIndex + 2     int sum = 0;
    int sum = 0;
    firstPos[0] = 1;
    
    for (int i = 0; i < (int)a.size(); i++) {
      sum += a[i]; 
      sum %= k;
      auto it = firstPos.find(sum);
      if (it != firstPos.end() && i + 2 - it->second >= 2) { return true;}
      
      int& v = firstPos[sum]; 
      if (v == 0) {v = i + 2;}
      
    }
    return false;
  }
} ;
