class Solution {
public:

    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        
        int LongestSubstring = 0;

        int PowerUniqueCharWindow = 0;

        vector<int> CharToCountInWIndow(128);

        for(int LeftPtr = 0, RightPtr = 0; RightPtr < s.size(); ++RightPtr){

            if(++CharToCountInWIndow[s[RightPtr]]  == 1){
                ++PowerUniqueCharWindow;
            }

            for(;PowerUniqueCharWindow == k + 1; ++LeftPtr){
                if(--CharToCountInWIndow[s[LeftPtr]]  == 0){
                    --PowerUniqueCharWindow;
                }
            }

            LongestSubstring = max(LongestSubstring, RightPtr - LeftPtr + 1);
        }


        return LongestSubstring;
    }
};
