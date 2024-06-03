class Solution {
public:
     int characterReplacement(string s, int k) {

        array<int, 128> CharToCountInWindow; 
        CharToCountInWindow.fill(0);

        int LengthLongestSubstring = 0;
        int LeftPtr = 0;
        int RightPtr = 0;
        int MaxCountRepeatSymb = 0;

        for (RightPtr = 0; RightPtr < s.size(); RightPtr++) {

            ++CharToCountInWindow[s[RightPtr]];
            MaxCountRepeatSymb = max(MaxCountRepeatSymb, CharToCountInWindow[s[RightPtr]]);

            if ((RightPtr - LeftPtr + 1) - MaxCountRepeatSymb == k + 1) {
                --CharToCountInWindow[s[LeftPtr]];
                ++LeftPtr;
            } else {
                LengthLongestSubstring = max(LengthLongestSubstring, (RightPtr - LeftPtr + 1));
            }
        }

        return LengthLongestSubstring;
    }
};
