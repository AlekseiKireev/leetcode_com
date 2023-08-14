class Solution {
public:

    int lengthOfLongestSubstring(string_view s) {
        int ans = 0;
        bool used[128] = {};
        int after = 0;
      
        for (int first = 0; first < (int)s.size(); first++) {
          
            while (after < (int)s.size() && !used[s[after]]) {
                used[s[after]] = true;
                after++;
            }

            assert(first <= after); // инваринат, демонстрирующий, что работаем с двумя указателями
          
            ans = max(ans, after - first);
            used[s[first]] = false;
          
        }
      
        return ans;
    }
    
};
