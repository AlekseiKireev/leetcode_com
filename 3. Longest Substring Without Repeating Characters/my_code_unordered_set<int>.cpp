class Solution {
public:
    int lengthOfLongestSubstring(string Str) {
        
        int Length = 0;

        unordered_set<int> CharToExistingInSlidingWindow;

        for (int LeftPtr = 0, RightPtr = 0; RightPtr < Str.size(); ++RightPtr) {

            if (CharToExistingInSlidingWindow.count(Str[RightPtr]) == 0) {
                
                Length = max(Length, RightPtr - LeftPtr + 1);
                
            } else {
                
                for (; CharToExistingInSlidingWindow.count(Str[RightPtr]) == 1; ++LeftPtr) {
                    CharToExistingInSlidingWindow.erase(Str[LeftPtr]);
                    
                }                
                
                // тут обновлять ответ нет смысла, так как сдвинули левую границу --> уменьшили размер окна по меньшей мере на 1
            }

            CharToExistingInSlidingWindow.insert(Str[RightPtr]);
        }

        return Length;
    }
};

/*
class Solution {
public:
    int lengthOfLongestSubstring(string Str) {
        
        int Length = 0;

        unordered_set<int> CharToExistingInSlidingWindow;

        for (int LeftPtr = 0, RightPtr = 0; RightPtr < Str.size(); ++RightPtr) {
                                               
                
            for (; CharToExistingInSlidingWindow.count(Str[RightPtr]) == 1; ++LeftPtr) {
                CharToExistingInSlidingWindow.erase(Str[LeftPtr]);
                
            }                
                            
            Length = max(Length, RightPtr - LeftPtr + 1);
            CharToExistingInSlidingWindow.insert(Str[RightPtr]);

        }

        return Length;
        
    }
};
*/
