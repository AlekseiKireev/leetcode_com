class Solution {
public:
    int characterReplacement(string_view S, int k) {

        int MaxCountRepeatSymb = 0;
        int LengthLongestSubstring = 1; // 1 <= s.length <= 10^5 --> есть хотя-бы один символ

        array<int, 26> CharToCountInWindow; 
        CharToCountInWindow.fill(0);

        for (int RightPtr = 0, LeftPtr = 0; RightPtr < S.size(); RightPtr++) {

            CharToCountInWindow[S[RightPtr] - 'A']++;
            MaxCountRepeatSymb = max(MaxCountRepeatSymb, CharToCountInWindow[S[RightPtr] - 'A']);

            int WindowLength = RightPtr - LeftPtr + 1;

            for (;LeftPtr < RightPtr && WindowLength - MaxCountRepeatSymb > k; LeftPtr++) {
                
                --CharToCountInWindow[S[LeftPtr] - 'A'];                                
                WindowLength = RightPtr - LeftPtr; // нет "+1" так как WindowIdx == (LeftPtr, RightPtr] 
            }

            /* MaxCountRepeatSymb достиг максимального значения, после того как RightPtr увеличивается на 1 
            выполнится условие WindowLength - MaxCountRepeatSymb > k и LeftPtr также увеличичться на 1*/
            LengthLongestSubstring = WindowLength;  // <--> LengthLongestSubstring = max(LengthLongestSubstring, WindowLength);

        }

        return LengthLongestSubstring;
    }
}
