const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

class Solution {

public:
   vector<int> findAnagrams(string_view s, string_view DesiredAnagr) { 
     
      vector<int> ans;
        
      if(s.size() < DesiredAnagr.size()){ return ans;}

      int count[1 + 'z'] = {}; // char of DesiredAnagr -, chars of s +
      int NonZero = 0;

      for (char c : DesiredAnagr) { 

         if( count[c] == 0){++NonZero;}
         count[c]--;
      }

      for (int j = 0; j < DesiredAnagr.size(); j++) { 

         const char c = s[j];

         if( count[c] == 0){++NonZero;}
         count[c]++;
         if(count[c] == 0){--NonZero;} // после сложжения в count[c]++ может быть count[c] == 0

      }

      if(NonZero == 0){ans.push_back(0);}


      for (int i = (int)DesiredAnagr.size(); i < (int)s.size()  ; i++) { 

         const char ToRemove = s[i - (int)DesiredAnagr.size()];
         const char ToAdd = s[i];

         if(count[ToRemove] == 0){++NonZero;}
         --count[ToRemove];        
         if(count[ToRemove] == 0){--NonZero;}


         if(count[ToAdd] == 0){++NonZero;}
         ++count[ToAdd];
         if(count[ToAdd] == 0){--NonZero;}

         if (NonZero == 0) {ans.push_back(i- (int)DesiredAnagr.size() + 1);}

      }

      return ans;
   }
} ;
