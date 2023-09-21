class Solution {

const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;

}();

public:

int search(const vector<int>& a, int target) { 

  // left и right -- противоположные инварианты: a[left] < target, a[right] >= target --> ответ будет right или -1
  int left = -1;
  int right = (int)a.size();
  // значения left и right выбирались на случай, если значения target находится вне границ вектора a, т.е. выполняется условие: target < a.front() || a.back() < target
    
  // примечательно также то, что данная реализация будет работать для пустого массива
  while (left + 1 < right) {
    int mid = (left + right) / 2;

    if (target <= a[mid]) { // удобно использовать только два вида оператора: <= AND < --> соответ-о для a[left] < target <= a[right] AND a[left] <= target < a[right]
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
