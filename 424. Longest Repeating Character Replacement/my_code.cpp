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

            if(WindowLength - MaxCountRepeatSymb == k + 1) {
                
                --CharToCountInWindow[S[LeftPtr] - 'A'];     
                LeftPtr++;
                
                --WindowLength; // убрали символ на который указывет LeftPtr
                   
            }

            /* MaxCountRepeatSymb достиг глобального максимального значения. после того как RightPtr увеличивается на 1 
            выполнится условие WindowLength - MaxCountRepeatSymb == k + 1 и LeftPtr также увеличичться на 1,
            ввиду чего WindowLength == LengthLongestSubstring
            Т.е. ответ не обновляется, если не обновляется MaxCountRepeatSymb
            */
            LengthLongestSubstring = WindowLength;  // <--> LengthLongestSubstring = max(LengthLongestSubstring, WindowLength);

        }

        return LengthLongestSubstring;
    }
};
