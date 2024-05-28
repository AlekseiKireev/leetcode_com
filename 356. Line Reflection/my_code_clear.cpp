
struct Myhash{

  size_t operator()(const pair<int, int> Pair) const {
      return Pair.first ^ Pair.second;
  }
};

class Solution {

int cnt;
unordered_map< pair<int, int>, bool, Myhash > Points;

public:

    bool isReflected(vector<vector<int>> &points) {
        
      int X_min = numeric_limits<int>::max();
      int X_max = numeric_limits<int>::min();

      for(auto point : points){

          int x = point.front();
          int y = point.back();
          X_min = min(x, X_min);
          X_max = max(x, X_max);
          Points[{x,y}] = true;
      }

      
      cnt = X_min + X_max;

      for(const auto point : Points){
          
          if(Points[{cnt - point.first.first, point.first.second}] == false){
            return false;
          }
      }


      return true;

    }
};
