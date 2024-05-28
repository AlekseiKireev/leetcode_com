#include <iostream>
#include<cassert>
#include <array>

using namespace std; 

constexpr int SIZE_ALPHABET = 128;

class Solution {

private:


    int LengthSubstr = 0;
public:

    int lengthOfLongestSubstringKDistinct(string_view s, const int k) {
    
    
        int PowerSlidingWindow = 0;
        
        array<int,SIZE_ALPHABET> CharToCount; CharToCount.fill(0);
        
        
        for(int LeftPtr = 0 , RightPtr = 0; RightPtr < s.size(); ++RightPtr){
            
            if(++CharToCount[s[RightPtr]] == 1){ // new unique char in Sliding Window
                ++PowerSlidingWindow;
            }
            
            /* мощность искомой подстроки превышает допустимую, необходимо сдвинуть левый указатель */
            for(;LeftPtr < RightPtr && PowerSlidingWindow > k; ++LeftPtr){ 
                
                if(--CharToCount[s[LeftPtr]] == 0){
                    --PowerSlidingWindow;
                }
            }
            
            // по сути этот оператор вообще не нужен! (обновление ответа нужно!
            if(PowerSlidingWindow <= k){ // "<=" обусловлен s = "aaaaaaaa", k = 3 --> 8
                LengthSubstr = max(LengthSubstr, RightPtr - LeftPtr + 1);
            }
            
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
    cout << Solution().lengthOfLongestSubstringKDistinct("abbbbbbc", 2) << '\n'; // 7
    cout << Solution().lengthOfLongestSubstringKDistinct("abcddefg", 3) << '\n'; // 4
    cout << Solution().lengthOfLongestSubstringKDistinct("aaaaaaaa", 3) << '\n'; // 8
    cout << Solution().lengthOfLongestSubstringKDistinct("abcefg", 1) << '\n'; // 1    
}
/*
0
0
1
2
4
*/

/*
class Solution {
public:

    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        
        int LongestSubstring = 0;

        int PowerUniqueCharWindow = 0;

        vector<int> CharToCountInWIndow(128);

        for(int LeftPtr = 0, RightPtr = 0; RightPtr < s.size(); ++RightPtr){

            if(++CharToCountInWIndow[s[RightPtr]]  == 1){
                ++PowerUniqueCharWindow;
            }

            for(;PowerUniqueCharWindow == k + 1; ++LeftPtr){
                if(--CharToCountInWIndow[s[LeftPtr]]  == 0){
                    --PowerUniqueCharWindow;
                }
            }

            LongestSubstring = max(LongestSubstring, RightPtr - LeftPtr + 1);
        }


        return LongestSubstring;
    }
};
*/
