class Solution {                                           
public:
  int numSquares(int n) { 
    
   vector<int> nSq(1 + n);
   for (int sum = 0; sum <= n; sum++) {nSq[sum] = sum;}

   for (int first = 1; first * first <= n; first++) {
     for (int sum = first * first; sum <= n; sum++) {
      nSq[sum] = min(nSq[sum], 1 + nSq[sum - first * first]);    
	}
    }

   return nSq[n];
  }
};
