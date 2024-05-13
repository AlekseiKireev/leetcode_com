#include <iostream>
#include<cassert>
#include <array>

using namespace std; 

constexpr int SIZE_ALPHABET = 128;

class Solution {

private:

    // https://github.com/SkosMartren/leetcode_com/blob/main/README.md#setting-the-size-of-an-array-in-a-private-section
    //constexpr int SIZE_ALPHABET = 128; // 'Solution::SIZE_ALPHABET' cannot be declared with 'constexpr' specifier // почему так?
    int LengthSubstr = 0;
public:

    int lengthOfLongestSubstringKDistinct(string_view s, int k) { // "0 <= k <= 50"

        if (k <= 0) { return LengthSubstr; }

        array<int, SIZE_ALPHABET> CharToCount; CharToCount.fill(0);

        for (int RightBorderWindow = 0, LeftBorderWindow = 0; RightBorderWindow <= s.size() - 1; ++RightBorderWindow) { // move Right ptr

            if (++CharToCount[s[RightBorderWindow]] == 1) { // новая буква (CharToCount[RightBorderWindow]) в sliding window
                --k;
            } // RightBorderWindow указывет на последний символ sliding window 

            for (;LeftBorderWindow < RightBorderWindow && k < 0; ++LeftBorderWindow) { // move Left ptr

                if (--CharToCount[s[LeftBorderWindow]] == 0) { // символа s[LeftBorderWindow] больше нет в sliding window
                    ++k;
                }
                
            } // LeftBorderWindow указывет на первый символ sliding window

            LengthSubstr = max(LengthSubstr, RightBorderWindow - LeftBorderWindow + 1);
            assert(LeftBorderWindow <= RightBorderWindow);
        }

        return LengthSubstr;
    }

};

int main() {
    cout << Solution().lengthOfLongestSubstringKDistinct("abc", 0) << '\n';
    cout << Solution().lengthOfLongestSubstringKDistinct("aaa", 0) << '\n';
    cout << Solution().lengthOfLongestSubstringKDistinct("aAaA", 1) << '\n';
    cout << Solution().lengthOfLongestSubstringKDistinct("aA~aA", 2) << '\n';
    cout << Solution().lengthOfLongestSubstringKDistinct("aAaA", 2) << '\n';
}
/*
0
0
1
2
4
*/
