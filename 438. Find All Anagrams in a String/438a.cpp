class Solution {

public:
   vector<int> findAnagrams(string_view s, string_view DesiredAnagr) { 
     
      vector<int> ans;

      for (int i = 0; i <= (int)s.size() - (int)DesiredAnagr.size(); i++) { // --> if((int)s.size() < (int)DesiredAnagr.size()){ return ans;}

         // https://en.cppreference.com/w/c/language/array_initialization -->
         // int a[3] = {}; // valid C++ way to zero-out a block-scope array; valid in C since C23
         int count[1 + 'z'] = {}; // char of DesiredAnagr +, chars of s -

         for (char c : DesiredAnagr) { 
            count[c]++;
         }

         for (int j = i, after = i + (int)DesiredAnagr.size(); j < after; j++) { 
            const char c = s[j];
            count[c]--;
         }

         bool good = true;

         for (char c = 'a'; c <= 'z'; c++) {

            if (count[c] != 0) { 
               good = false; 
               break;
            }

         }

         if (good) {ans.push_back(i);}

      }

      return ans;
   }
   
};
