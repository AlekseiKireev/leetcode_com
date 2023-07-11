class Solution {

const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;

}();

public:

int search(const vector<int>& a, int target) { 

  int left = -1;
  int right = (int)a.size();
  // a[left] < target, a[right] >= target 

  while (left + 1 < right) {
    int mid = (left + right) / 2;

    if (a[mid] >= target) {
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
