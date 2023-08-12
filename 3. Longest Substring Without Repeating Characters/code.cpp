class Solution {
public:
    int lengthOfLongestSubstring(string_view s) {
        
        unordered_map<char, int> CharToEndIdx;
        int LeftPtr = -1;
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) { // i == RightPtr
            
            // CharToEndIdx.count(s[i]) != 0 <--> символ уже встречался 
            if (CharToEndIdx.count(s[i]) != 0) {LeftPtr = max(LeftPtr, CharToEndIdx[s[i]]);}
            
            CharToEndIdx[s[i]] = i;

            maxLen = max(maxLen, i-LeftPtr);
            
        }
        
        return maxLen;
    }
};

//https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/1737/c-code-in-9-lines/
