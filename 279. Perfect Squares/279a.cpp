class Solution {

  bool perfectSquare(int n) { 
    int sq = round(sqrt(n)); 
    return sq * sq == n;
  }

  int numSquares(int n, int rem) {
    assert(rem >= 1);
    if (perfectSquare(n)) {
      return 1;
    }
    if (rem == 1) {
      return 5;
    }
    int ans = 5;
    for (int first = 1; first * first <= n; first++) {
      ans = min(ans, 1 + numSquares(n - first * first, rem - 1));
    }

    return ans;
  }
public:

  int numSquares(int n) {
    return numSquares(n, 4);
  }
};
