const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

class Solution {

   bool validPalindrome(const string &s, size_t first, size_t last, int nErrors) { 
     while (true) {
       if (first >= last) {
         return true;
       }
       if (s[first] != s[last]) {
         if (nErrors == 0) {
           return false;
         } else {
           return
             validPalindrome(s, first + 1, last, nErrors - 1) || 
             validPalindrome(s, first, last - 1, nErrors - 1);
         }
       } 
       first++;
       last--;
     }
   }


public:
   bool validPalindrome(const string &s) {
     return validPalindrome(s, 0, s.size() - 1, 1);
    }
};
