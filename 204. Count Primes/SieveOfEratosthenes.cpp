class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) {
      return 0;
    }
    
    vector<bool> isPrime = sieveEratosthenes(n);
    int count = 0; // Переменная для подсчета простых чисел
    for (bool prime : isPrime) {
      if (prime) {
        ++count;
      }
    }
    return count;
  }

 private:
  vector<bool> sieveEratosthenes(int n) {
    vector<bool> isPrime(n, true);
    isPrime[0] = false; // 0 не является простым числом
    isPrime[1] = false; // 1 не является простым числом
    
    for (int i = 2; i < n; ++i) {
      if (isPrime[i]) {
        for (int j = 2 * i; j < n; j += i) { 
          isPrime[j] = false; // Все числа, кратные i, не являются простыми
        }
      }
    }
    return isPrime;
  }
};
/* optimization:
class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) {
      return 0;
    }
    
    vector<bool> isPrime = sieveEratosthenes(n);
    int count = 0; // Переменная для подсчета простых чисел
    for (bool prime : isPrime) {
      if (prime) {
        ++count;
      }
    }
    return count;
  }

 private:
  vector<bool> sieveEratosthenes(int n) {
    vector<bool> isPrime(n, true);
    isPrime[0] = false; // 0 не является простым числом
    isPrime[1] = false; // 1 не является простым числом
    
    for (int i = 2; i*i < n; ++i) {
      if (isPrime[i]) {
        for (int j = i * i; j < n; j += i) { // 2 * i было исключено ранее при обработке i=2, аналогично 3*i,..., (i-1)*i
          isPrime[j] = false; // Все числа, кратные i, не являются простыми
        }
      }
    }
    return isPrime;
  }
};

*/
