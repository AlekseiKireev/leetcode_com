class Solution {
public:
  int numSquares(int n) {

    // nSq[i] == наименьшее число слагаемых в квадратном разложении числа i : i \in |N --> искомое == nSq.back() == nSq[n]
   vector<int> nSq(1 + n, 5); // 5 - локальный максимум, так как ответ не может превышать 4 ввиду "Теорема Лагранжа о сумме четырёх квадратов"
   nSq[0] = 0;

     for (int sum = 1; sum <= n; sum++) {
       for (int first = 1; first * first <= sum; first++) { // first * first <= sum <-->  0 <= sum - first * first
         nSq[sum] = min(nSq[sum], 1 + nSq[sum - first * first]);  
       } 
    }
   return nSq[n];
  }
};
