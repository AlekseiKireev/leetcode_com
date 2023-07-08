class Solution {
public:
  int numSquares(int n) {

   vector<int> nSq(1 + n, 5);
   nSq[0] = 0;

     for (int sum = 1; sum <= n; sum++) {
       for (int first = 1; first * first <= sum; first++) { 
         nSq[sum] = min(nSq[sum], 1 + nSq[sum - first * first]);  
       } 
    }
   return nSq[n];
  }
};
