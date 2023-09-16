class Solution {                   
public:
 void rotate(vector<vector<int>>& a) {    
   reverse(a.begin(), a.end());
   int n = (int)a.size();
   for (int i = 0; i < n; i++) {
     for (int j = i + 1; j < n; j++) {  
      swap(a[j][i], a[i][j]);
     }
   }
 }                                   
} ;
