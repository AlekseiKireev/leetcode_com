class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
               
        for (int i = 0; i + 2 < (int)a.size(); i++) { // move i [== first ptr] forward
           
            if (i > 0 && a[i] == a[i - 1]) {continue;}

            int k = (int)a.size() - 1;
            for (int j = i + 1; j < k; j++) { // move j [ == second ptr] forward

                while (j < k - 1 && a[i] + a[j] + a[k] > 0) { // move k [ == third ptr] backward
                    k--;
                }
                
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
