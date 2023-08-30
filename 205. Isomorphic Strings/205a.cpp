class Solution {
public:

  bool isIsomorphic(const string &s, const string &t) { 

    assert(s.size() == t.size());
    vector<int> sToT(128, -1);
    vector<int> tToS(128, -1);

    for (size_t i = 0; i < s.size(); i++) { 
      char sc = s[i];
      char tc = t[i];
      
      assert(0 <= sc && sc <= 127); 
      assert(0 <= tc && tc <= 127); 
      
      if (sToT[sc] == tc && tToS[tc] == sc) {
        // ok
      } else if (sToT[sc] == -1 && tToS[tc] == -1) { 

        sToT[sc] = tc;
        tToS[tc] = sc;
        
      } else {
        return false;
      }
    }
    return true;
  }

};

