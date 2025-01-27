/*
Time complexity: O(n*sqrt(n)) outer loop is of sqrt(n) iterations and in the inner loop <n iterations roughly.
Space Complexity: O(n).
*/  
class Solution {
public:
  int numSquares(int n) {
    
    
    // nSq[i] == наименьшее число натуральных слагаемых в квадратном разложении числа i : i \in |N --> искомое == nSq.back() == nSq[n]
   vector<int> nSq(1 + n, 5); // 5 - локальный максимум, так как ответ не может превышать 4 ввиду "Теорема Лагранжа о сумме четырёх квадратов"
    // по меньшей мере необходим, чтобы гарантировано изначально выполнилось условие в:  nSq[sum] = min(nSq[sum], 1 + nSq[sum - first * first])
    
   nSq[0] = 0; // 0 = 0^2 + 0^2 + 0^2 + 0^2 --> в разложении нет ни одного натруального числа --> nSq[0] = 0

     for (int sum = 1; sum <= n; sum++) {
       for (int first = 1; first * first <= sum; first++) { // first * first <= sum <-->  0 <= sum - first * first -- что используется далее в nSq[sum - first * first]

         // nSq[numb - dt * dt] + 1 == наименьшее число натуральных слагаемых в квадратном разложении числа nSq[numb]
         // min -- по условию задачи
         nSq[sum] = min(nSq[sum],  nSq[sum - first * first] + 1 );   // "+ 1" обусловлен тем, что из "sum - first * first" можно получить "sum" 
         // добавлением одного perfect square = first * first -- значит количество слагаемых увеличивается на 1 в сравнении с nSq[sum - first * first]
         
       } 
    }
   return nSq[n];
  }
};
