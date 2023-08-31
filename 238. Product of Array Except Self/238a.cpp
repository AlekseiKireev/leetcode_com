const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

class Solution {
public:
   vector<int> productExceptSelf(const vector<int>& a) { 
       vector<int> ans(a.size());
       ans[0] = 1;
       for (int i = 1; i < (int)a.size(); i++) { 
           ans[i] = ans[i - 1] * a[i - 1];
       }
       int suffix = 1;
       for (int i = (int)a.size() - 2; i >= 0; i--) { 
           suffix *= a[i + 1];
           ans[i] *= suffix;
       }
       return ans;
   }
};

