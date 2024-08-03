class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0; // Нет простых чисел меньше 2

        std::vector<bool> notPrime(n, false);
        int count = 0;
        
        for (int i = 2; i < n; i++) {
            if (!notPrime[i]) {
                count++;
                for (int j = 2; i * j < n; j++) {
                    notPrime[i * j] = true;
                }
            }
        }
        
        return count;
    }
};
