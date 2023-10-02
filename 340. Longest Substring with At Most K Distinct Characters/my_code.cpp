#include <iostream>
#include <string>
#include<string_view>
#include <array>

using namespace std;

constexpr int SIZE_ALPHABET = 26;

class Solution {

private:

    //constexpr int SIZE_ALPHABET = 26; // 'Solution::SIZE_ALPHABET' cannot be declared with 'constexpr' specifier // почему так?
    int LengthSubstr = 0;
public:

    int lengthOfLongestSubstringKDistinct(string_view s, int k) { // "0 <= k <= 50"

        if(k <= 0){ return LengthSubstr; }


        array<int, SIZE_ALPHABET> CharToCount; CharToCount.fill(0);        

        for (int RightBorderWindow = 0, LeftBorderWindow = 0; RightBorderWindow <= s.size() - 1; ++RightBorderWindow) { // move Right ptr

            //if (++CharToCount[s[RightBorderWindow] - 'a'] == 1) { // новая буква (CharToCount[RightBorderWindow]) в sliding window
            //    --k;
            //} // RightBorderWindow указывет на последний символ sliding window 

             // лучше не сдвигать двумя способами правй указатель, не удобно / понижает читабельность / повышает вероятность ошибки
              while(RightBorderWindow < s.size() - 1 && k > 0){

                      if(++CharToCount[RightBorderWindow] == 1){ // новая буква (CharToCount[RightBorderWindow]) в sliding window
                          --k;
                      }
                      ++RightBorderWindow;

              } // RightBorderWindow указывет на последний символ sliding window
              

            while (LeftBorderWindow < RightBorderWindow && k < 0) { // move Left ptr

                if (--CharToCount[s[LeftBorderWindow] - 'a'] == 0) {
                    ++k;
                }
                ++LeftBorderWindow;
            } // LeftBorderWindow указывет на первый символ sliding window

            LengthSubstr = max(LengthSubstr, RightBorderWindow - LeftBorderWindow + 1);

        }

        return LengthSubstr;
    }

};

//int main() {
//    cout << Solution().lengthOfLongestSubstringKDistinct("aaaa", 0) << '\n';
//    cout << Solution().lengthOfLongestSubstringKDistinct("aaaa", 1) << '\n';
//    cout << Solution().lengthOfLongestSubstringKDistinct("aaaa", 2) << '\n';
//    cout << Solution().lengthOfLongestSubstringKDistinct("aaaa", 4) << '\n';
//    cout << Solution().lengthOfLongestSubstringKDistinct("aaaa", 42) << '\n';
//
//}
