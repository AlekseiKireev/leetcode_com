class Solution {
public:
    int characterReplacement(string_view S, int k) {

        int MaxCountRepeatVal = 0;
        int ans = -1;

        array<int, 26> CharToCountInSuffix; // Suffix лежит в границах [LeftPtr, RightPtr]
        CharToCountInSuffix.fill(0);

        for (int RightPtr = 0, LeftPtr = 0; RightPtr < S.size(); RightPtr++) {

            CharToCountInSuffix[S[RightPtr] - 'A']++;
            MaxCountRepeatVal = max(MaxCountRepeatVal, CharToCountInSuffix[S[RightPtr] - 'A']);

            int WindowLength = RightPtr - LeftPtr + 1;
            if (WindowLength - MaxCountRepeatVal > k) {
                --CharToCountInSuffix[S[LeftPtr] - 'A'];
                LeftPtr++;
                WindowLength = RightPtr - LeftPtr + 1;
            }

            ans = max(ans, WindowLength);

        }

        return ans;
    }
};
