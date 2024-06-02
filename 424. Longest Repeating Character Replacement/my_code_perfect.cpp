class Solution {
public:
    int characterReplacement(string_view S, int k) {

        int MaxCountRepeatSymb = 0;
        int LengthLongestSubstring = 0; 

        array<int, 128> CharToCountInWindow; 
        CharToCountInWindow.fill(0);

        for (int RightPtr = 0, LeftPtr = 0; RightPtr < S.size(); RightPtr++) {

            ++CharToCountInWindow[S[RightPtr]];
            MaxCountRepeatSymb = max(MaxCountRepeatSymb, CharToCountInWindow[S[RightPtr]]);

            ++LengthLongestSubstring;

            if (LengthLongestSubstring - MaxCountRepeatSymb == k + 1) {
                
                --CharToCountInWindow[S[LeftPtr] ];    
                ++LeftPtr;
                --LengthLongestSubstring;
                
            } // LengthLongestSubstring - MaxCountRepeatSymb <= k

        }

        return LengthLongestSubstring;
    }
};
