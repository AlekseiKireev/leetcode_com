class Solution {
public:
    int characterReplacement(string_view S, int k) {

        int MaxCountRepeatSymb = 0;
        int LengthLongestSubstring = -1;

        array<int, 26> CharToCountInSuffix; // Suffix лежит в границах [LeftPtr, RightPtr]
        CharToCountInSuffix.fill(0);

        for (int RightPtr = 0, LeftPtr = 0; RightPtr < S.size(); RightPtr++) {

            CharToCountInSuffix[S[RightPtr] - 'A']++;
            MaxCountRepeatSymb = max(MaxCountRepeatSymb, CharToCountInSuffix[S[RightPtr] - 'A']);

            int WindowLength = RightPtr - LeftPtr + 1;
            if (WindowLength - MaxCountRepeatSymb > k) {
                --CharToCountInSuffix[S[LeftPtr] - 'A'];
                LeftPtr++;
                WindowLength = RightPtr - LeftPtr + 1;
            }

            LengthLongestSubstring = max(LengthLongestSubstring, WindowLength);

        }

        return LengthLongestSubstring;
    }
};
