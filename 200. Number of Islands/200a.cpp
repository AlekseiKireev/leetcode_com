const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

class Solution {
public:
   int numIslands(vector<vector<char>>& grid) {
      int ans = 0;  
      
      for (int i = 0; i < (int)grid.size(); i++) {
        for (int j = 0; j < (int)grid[i].size(); j++) { 

           if (grid[i][j] == '1') {
             fill(grid, i, j);
             ans++;
           }

        }
      }
      return ans;
   }

   void fill(vector<vector<char>>& grid, int i, int j) {
      
      if (i < 0 || j < 0 || i >= (int)grid.size() || j >= grid[i].size()) { return;}
      
      if (grid[i][j] != '1') {return;}

      grid[i][j] = '0';
      fill(grid, i + 1, j); 
      fill(grid, i - 1, j); 
      fill(grid, i, j + 1); 
      fill(grid, i, j - 1);
   }
} ;

