class Solution {
public:
    bool isOneEditDistance(string_view s, string_view t) {
      
        int m = s.size(), n = t.size();
        if (m - n > 1) return false;
        if (m < n) return isOneEditDistance(t, s);
        assert(m == n || m == n + 1); // t.size() <= s.size()
      
        for (int i = 0; i < n; ++i) { // итерируемся по строке с минимальной длиной
          
            if (s[i] != t[i]) {
                if (m == n) { // Replace 
                  return s.substr(i + 1) == t.substr(i + 1);
                }
              
                return s.substr(i + 1) == t.substr(i); // Delete s[i] or Insert before t[i]
            }
        }
        
        //return true; // error: s = "", t = ""
        return m == n + 1; // ab abc
    }
};
