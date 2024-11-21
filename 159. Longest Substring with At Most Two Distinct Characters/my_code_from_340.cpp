#include <iostream>
#include<cassert>
#include <array>
#include <string_view>

using namespace std; 
/*
Time complexity: O(n)
Space complexity: O(alphabet)
*/
constexpr int SIZE_ALPHABET = 128;

class Solution {

private:

    // https://github.com/SkosMartren/leetcode_com/blob/main/README.md#setting-the-size-of-an-array-in-a-private-section
    //constexpr int SIZE_ALPHABET = 128; // 'Solution::SIZE_ALPHABET' cannot be declared with 'constexpr' specifier // почему так?
    int LengthSubstr = 0;
public:

    int lengthOfLongestSubstringTwoDistinct(string_view s, int k = 2) { // "0 <= k <= 50"

        if (k <= 0) { return LengthSubstr; }

        array<int, SIZE_ALPHABET> CharToCount; CharToCount.fill(0);

        for (int RightBorderWindow = 0, LeftBorderWindow = 0; RightBorderWindow <= s.size() - 1; ++RightBorderWindow) { // move Right ptr

            if (++CharToCount[s[RightBorderWindow]] == 1) { // новая буква (CharToCount[RightBorderWindow]) в sliding window
                --k;
            } // RightBorderWindow указывет на последний символ sliding window 

            while (LeftBorderWindow < RightBorderWindow && k < 0) { // move Left ptr

                if (--CharToCount[s[LeftBorderWindow]] == 0) {
                    ++k;
                }
                ++LeftBorderWindow;
            } // LeftBorderWindow указывет на первый символ sliding window

            LengthSubstr = max(LengthSubstr, RightBorderWindow - LeftBorderWindow + 1);
            assert(LeftBorderWindow <= RightBorderWindow);
        }

        return LengthSubstr;
    }

};

int main() {
    cout << Solution().lengthOfLongestSubstringTwoDistinct("abc") << '\n';
    cout << Solution().lengthOfLongestSubstringTwoDistinct("aaa") << '\n';
    cout << Solution().lengthOfLongestSubstringTwoDistinct("aAaA") << '\n';
    cout << Solution().lengthOfLongestSubstringTwoDistinct("aA~aA") << '\n';
    cout << Solution().lengthOfLongestSubstringTwoDistinct("aAaA") << '\n';
    cout << Solution().lengthOfLongestSubstringTwoDistinct("ccaabbb") << '\n';
    cout << Solution().lengthOfLongestSubstringTwoDistinct("eceba") << '\n';    
}
/*
2
3
4
2
4
5
3
*/
