class Solution {
public:
    int characterReplacement(string_view S, int k) {

        int MaxCountRepeatSymb = 0;
        int LengthLongestSubstring = -1;

        array<int, 26> CharToCountInSuffix; // Suffix лежит в границах [LeftPtr, RightPtr]
        CharToCountInSuffix.fill(0);

        for (int RightPtr = 0, LeftPtr = 0; RightPtr < S.size(); RightPtr++) {

            CharToCountInSuffix[S[RightPtr] - 'A']++;
            MaxCountRepeatSymb = max(MaxCountRepeatSymb, CharToCountInSuffix[S[RightPtr] - 'A']); // MaxCountRepeatSymb in Suffix

            int WindowLength = RightPtr - LeftPtr + 1;
            //if (WindowLength - MaxCountRepeatSymb > k) { // good!
            while (LeftPtr < RightPtr && WindowLength - MaxCountRepeatSymb > k) { // разве при изменении LeftPtr не надо обновлять MaxCountRepeatSymb?
                --CharToCountInSuffix[S[LeftPtr] - 'A'];
                LeftPtr++;
                // MaxCountRepeatSymb = max(MaxCountRepeatSymb, CharToCountInSuffix[S[LeftPtr] - 'A']); // работает с этой строкой, но, работает и без нее!
                WindowLength = RightPtr - LeftPtr + 1;
            }
            
            LengthLongestSubstring = WindowLength; // good! WHY?!
            //LengthLongestSubstring = max(LengthLongestSubstring, WindowLength);

        }

        return LengthLongestSubstring;
    }
};
