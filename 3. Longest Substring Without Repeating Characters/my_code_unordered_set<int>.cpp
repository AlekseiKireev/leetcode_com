class Solution {
public:
    int lengthOfLongestSubstring(string Str) {
        
        const int SIZE = Str.size();
        int Length = 0;

        unordered_set<int> CharToExistingInSlidingWindow;

        for (int LeftPtr = 0, RightPtr = 0; RightPtr < SIZE; ++RightPtr) {

            if (CharToExistingInSlidingWindow.count(Str[RightPtr]) == 0) {
                CharToExistingInSlidingWindow.insert(Str[RightPtr]);
                Length = max(Length, RightPtr - LeftPtr + 1);
            } else {
                while (CharToExistingInSlidingWindow.count(Str[RightPtr]) == 1) {
                    CharToExistingInSlidingWindow.erase(Str[LeftPtr]);
                    ++LeftPtr;
                }
                CharToExistingInSlidingWindow.insert(Str[RightPtr]);
                // тут обновлять ответ нет смысла, так как сдвинули левую границу --> уменьшили размер окна по меньшей мере на 1
            }
        }

        return Length;
    }
};
