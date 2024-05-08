const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

class Solution {
public:
 int maxProfit(const vector<int>& a) {
     int ans = 0;
     for (int i = 0; i < (int)a.size(); i++) {
       for (int j = i + 1; j < (int)a.size(); j++) { 
         ans = max(ans, a[j] - a[i]);
       }
     }
     return ans;
  }
};
