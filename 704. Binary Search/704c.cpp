class Solution {

const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;

}();

public:

int search(const vector<int>& a, int target) { 

  // left и right -- противоположные инварианты: left < target, right >= target
  int left = -1;
  int right = (int)a.size();

  // примечательно также то, что данная реализация будет работать для пустого массива
  while (left + 1 < right) {
    int mid = (left + right) / 2;

    if (target <= a[mid]) {
      right = mid;
    } else {
      left = mid;
    }
  }

  if (right == (int)a.size()) {
    return -1;
  } else if (a[right] > target) {
    return -1; 
  } else {
    return right;
  }
}

};
