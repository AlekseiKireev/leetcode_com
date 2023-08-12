class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int ans = 0;

        for (int first = 0; first < (int)s.size(); first++) {
            bool used[128] = {};
            
            for (int i = first; i < (int)s.size(); i++) {
                char c = s[i];

                if (used[c]) {break;}

                used[c] = true;
                ans = max(ans, i - first + 1);
            }
        }

        return ans;

    }
};
