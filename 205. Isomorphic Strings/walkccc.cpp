class Solution {
 public:
  bool isIsomorphic(string s, string t) {

    // " 29 / 44 testcases passed s = "13" t = "42" " --> размер более 26 
    // " 36 / 44 testcases passed s = "qwertyuiop[]asdfghjkl;'\\zxcvbnm,./" t = "',.pyfgcrl/=aoeuidhtns-\\;qjkxbmwvz" " --> размер более 128 

    array<int, 128> charToIndex_s; charToIndex_s.fill(0);
    array<int, 128> charToIndex_t; charToIndex_t.fill(0);

    for (int i = 0; i < s.length(); ++i) {

      if (charToIndex_s[s[i]] != charToIndex_t[t[i]]){return false;}

      // charToIndex_s[s[i]] == charToIndex_t[t[i]]
      charToIndex_s[s[i]] = i + 1;
      charToIndex_t[t[i]] = i + 1;

    }

    return true;
  }
};
