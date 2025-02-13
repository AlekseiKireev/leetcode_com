class Solution {
    
 public:
  vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
      
    vector<vector<int>> ans;
    int Idx1 = 0;
    int Idx2 = 0;

    while (Idx1 < encoded1.size() && Idx2 < encoded2.size()) { // не выйдем из цикла, пока не окончатся minFrequency
      const int product = encoded1[Idx1][0] * encoded2[Idx2][0];
      const int minFrequency = min(encoded1[Idx1][1], encoded2[Idx2][1]);

      if (!ans.empty() && product == ans.back()[0]) {
        ans.back()[1] += minFrequency;
      } else {
        ans.push_back({product, minFrequency});
      }

      encoded1[Idx1][1] -= minFrequency;
      encoded2[Idx2][1] -= minFrequency;

      Idx1 += (encoded1[Idx1][1] == 0);
      Idx2 += (encoded2[Idx2][1] == 0);
    }

    return ans;
  }
};
