class Solution {
 public:
  vector<int> findAnagrams(string_view s, string_view p) {
    
    vector<int> count(128);
    for (const char c : p) {++count[c];}


    int required = p.size();
    vector<int> ans;

    for (int l = 0, r = 0; r < s.size(); ++r) {

      if (--count[s[r]] >= 0) {--required;}
      
      while (required == 0) {

        if (r - l + 1 == p.size()) {ans.push_back(l);}

        if (++count[s[l++]] > 0) {++required;}
        
      }
    }

    return ans;
  }
};
