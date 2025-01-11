class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();

    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> IdxDiagMatrixToVal;

    for (int i = 0; i < m; ++i){
      for (int j = 0; j < n; ++j) {
        IdxDiagMatrixToVal[i - j].push(mat[i][j]);
      }
    }

    for (int i = 0; i < m; ++i){
      for (int j = 0; j < n; ++j) {
        mat[i][j] = IdxDiagMatrixToVal[i - j].top(); 
        IdxDiagMatrixToVal[i - j].pop();
      }
    }
    return mat;
  }
};
