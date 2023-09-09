class Solution { 
public:
  int maxDistToClosest(const vector<int>& a) {
    int prev = 0;
    while (a[prev] == 0) {
      prev++;
    }
    int max = prev;
    for (int i = prev + 1; i < (int)a.size(); i++) { 
      if (a[i] == 1) {
        max = std::max(max, (i - prev) / 2); 
        prev = i;
      }
    }
    max = std::max(max, (int)a.size() - 1 - prev); 
    return max;
  }
};
