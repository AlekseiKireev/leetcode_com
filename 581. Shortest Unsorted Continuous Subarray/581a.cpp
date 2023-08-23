const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

class Solution {
public:
  int findUnsortedSubarray(const vector<int>& a) { 

    int max = a[0];
    int last = -1; // RightBorder

    for (int i = 0; i < (int)a.size(); i++) { 

      max = std::max(max, a[i]);
      if (a[i] < max) {last = i;}

    }

    if (last == -1) {return 0;} // последовательность отсортирована 

    int min = a.back();
    int first = -1; // LeftBorder

    for (int i = (int)a.size() - 1; i >= 0; i--) { 

      min = std::min(min, a[i]);
      if (a[i] > min) {first = i;}

    }

    return last - first + 1;

  }

};

