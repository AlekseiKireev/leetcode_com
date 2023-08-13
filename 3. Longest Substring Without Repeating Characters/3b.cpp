class Solution {
public:

    int lengthOfLongestSubstring(string_view s) {
        int ans = 0;
        for (int len = 1; len < 128; len++) {
          
            bool goodLen = false;
          
            for (int first = 0; first + len <= (int)s.size(); first++) {
              
                bool used[128] = {};
                bool good = true;
              
                for (int i = first; i < first + len; i++) {
                    char c = s[i];
                  
                    if (used[c]) {
                        good = false;
                        break;
                    }
                  
                    used[c] = true;
                }
              
                if (good) {
                    ans = len;
                    goodLen = true;
                    break;
                }
              
            }
          
            if (!goodLen) {break;}
          
        }
        return ans;
      
    }
};
