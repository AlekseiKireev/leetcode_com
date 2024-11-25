/*
Time complexity: O(n)
Space complexity: O(alphabet)
*/
class Solution {
public:
     int characterReplacement(string s, int k) {

        array<int, 128> CharToCountInWindow; 
        CharToCountInWindow.fill(0);

        int LengthLongestSubstring = 0;
        int LeftPtr = 0;
        int RightPtr = 0;
        int MaxCountRepeatSymb = 0;

        for (RightPtr = 0; RightPtr < s.size(); RightPtr++) {

            ++CharToCountInWindow[s[RightPtr]];
            MaxCountRepeatSymb = max(MaxCountRepeatSymb, CharToCountInWindow[s[RightPtr]]);

            if ((RightPtr - LeftPtr + 1) - MaxCountRepeatSymb == k + 1) { // (RightPtr - LeftPtr + 1) - MaxCountRepeatSymb -- количество символов, отличных от MaxCountRepeatSymb --> из заменяем
                --CharToCountInWindow[s[LeftPtr]];
                ++LeftPtr;
            } 

            // (RightPtr - LeftPtr + 1) - MaxCountRepeatSymb <= k 
            LengthLongestSubstring = max(LengthLongestSubstring, (RightPtr - LeftPtr + 1));
            
        }

        return LengthLongestSubstring;
    }
};
