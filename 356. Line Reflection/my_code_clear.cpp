
struct Myhash{

  size_t operator()(const pair<int, int> Pair) const { // без const будет ошибка
      return Pair.first ^ Pair.second;
  }
};

class Solution {

int cnt;
unordered_map< pair<int, int>, bool, Myhash > HashPoints;

public:

    bool isReflected(vector<vector<int>> &points) {
        
      int X_min = numeric_limits<int>::max();
      int X_max = numeric_limits<int>::min();

      for(auto point : points){

          int x = point.front();
          int y = point.back();
          X_min = min(x, X_min);
          X_max = max(x, X_max);
          HashPoints[{x,y}] = true;
      }

      
      cnt = X_min + X_max;

      for(const auto point : HashPoints){
          
          if(HashPoints[{cnt - point.first.first, point.first.second}] == false){
            return false;
          }
      }

      return true;

    }
};
