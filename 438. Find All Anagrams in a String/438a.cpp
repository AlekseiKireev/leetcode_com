class Solution {

public:
   vector<int> findAnagrams(string_view s, string_view DesiredAnagr) { 
     
      vector<int> ans;

      for (int i = 0; i <= (int)s.size() - (int)DesiredAnagr.size(); i++) { 

         int count[1 + 'z'] = {0}; // char of DesiredAnagr +, chars of s -

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
