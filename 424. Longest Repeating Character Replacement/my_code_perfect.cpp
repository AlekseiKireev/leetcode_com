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

            for (;LengthLongestSubstring - MaxCountRepeatSymb == k + 1; LeftPtr++) {
                
                --CharToCountInWindow[S[LeftPtr] ];                                
                --LengthLongestSubstring;
            }

        }

        return LengthLongestSubstring;
    }
};
