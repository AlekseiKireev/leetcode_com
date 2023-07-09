class Solution {

  bool perfectSquare(int n) { 
    int sq = round(sqrt(n)); 
    return sq * sq == n;
  }

  int numSquares(int n, int rem) {
    assert(rem >= 1);
    
    if (perfectSquare(n)) {return 1;}
    
    if (rem == 1) {return 5;} // 4 слагаемое в разложении не является точным квадратом [иначе бы perfectSquare(n) == true и вышли бы из рекурсии в предыдущем условном операторе]
                              // , например: 13 = 1 + 1 + 1 + 10  -- возвращаем локальынй максимум, так как такая сумма не подходит под условие заадчи --> 
                              // в ans = min(ans, 1 + numSquares(n - first * first, rem - 1)); должны выбрать ans
    
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
