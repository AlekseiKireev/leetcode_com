class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(), a.end());
        if(a[a.size() - 1] < 0 || a[0] > 0){return ans;} // optimization
        
        vector<vector<int>> ans;
        
        for (int i = 0; i + 2 < (int)a.size(); i++) { // move i [== first ptr] forward

            //___________________________________________________
            // optimization
            if (i > 0 && a[i] == a[i - 1]) {continue;}
            if (a[i] + a[i + 1] + a[i + 2] > 0) {continue;}
            if (a[i] + a[a.size() - 1] + a[a.size() - 2] < 0) {continue;}
            //___________________________________________________
            
            int j = i + 1;
            int k = (int)a.size() - 1;
            for (int j = i + 1; j < k; j++) { // move j [ == second ptr] forward
                
                while (j < k - 1 && a[i] + a[j] + a[k] > 0) { // move k [ == third ptr] backward
                    k--;
                }
                
                assert(i < j && j < k);
                if (a[i] + a[j] + a[k] == 0) {
                    if (ans.empty() || a[i] != ans.back()[0] || a[j] != ans.back()[1] || a[k] != ans.back()[2]) {
                        ans.push_back({ a[i], a[j], a[k] });
                    }
                }
            }
        }
        return ans;
    }
};

