class Solution {
public:
  int maxDistToClosest(const vector<int>& a) { 
    int prey = -1;
    int max = 0;
    for (int i = 0; i < (int)a.size(); i++) { 
      if (a[i] == 1) {
        if (prey == -1) {
          max = std::max(max, i);
        } else {
          max = std::max(max, (i - prey) / 2);
        }
        prey = i;
      }
    }
    max = std::max(max, (int)a.size() - 1 - prey); 
    return max;
  }
};
