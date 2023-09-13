class Solution {
public:
    int characterReplacement(string_view S, int k) {

        int maxFrequency = 0;
        int LengthLongestSubstring = -1;

        array<int, 26> CharToCountInSuffix; // Suffix лежит в границах [LeftPtr, RightPtr]
        CharToCountInSuffix.fill(0);

        for (int RightPtr = 0, LeftPtr = 0; RightPtr < S.size(); RightPtr++) {

            CharToCountInSuffix[S[RightPtr] - 'A']++;
            maxFrequency = max(maxFrequency, CharToCountInSuffix[S[RightPtr] - 'A']); // maxFrequency in Suffix

            int WindowLength = RightPtr - LeftPtr + 1;
            //if (WindowLength - maxFrequency > k) { // good!
            while (LeftPtr < RightPtr && WindowLength - maxFrequency > k) { // разве при изменении LeftPtr не надо обновлять maxFrequency?
                --CharToCountInSuffix[S[LeftPtr] - 'A'];
                LeftPtr++;
                // maxFrequency = max(maxFrequency, CharToCountInSuffix[S[LeftPtr] - 'A']); // работает с этой строкой, но, работает и без нее!
                WindowLength = RightPtr - LeftPtr + 1;
            }
            
            LengthLongestSubstring = WindowLength; // good! WHY?!
            //LengthLongestSubstring = max(LengthLongestSubstring, WindowLength);

        }

        return LengthLongestSubstring;
    }
};
