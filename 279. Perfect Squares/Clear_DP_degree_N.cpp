class Solution {
public:
    const int DEGREE = 2;


    size_t power(int base, int exponent) {
        size_t result = 1;
        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }
        return result;
    }

    int numSquares(int N) {

        std::vector<int> DP(N + 1, 101); 
        DP[0] = 0; 

        for (size_t sum = 1; sum <= N; sum++) {


            for (int first = 1; power(first, DEGREE) <= sum; first++) { 
                DP[sum] = min(DP[sum], DP[sum - power(first, DEGREE)] + 1); 
            }
        }
        return DP.back();
    }
};
