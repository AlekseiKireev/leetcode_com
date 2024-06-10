class Solution {
public:
    int lengthOfLongestSubstring(string Str) {

        vector<bool> CharToExistingInSlidingWindow(128);

        int Length = 0;

        // для каждого сдвига правого указателя оптимально смещается левый указатель --> 
        // достаточно одного прохода правого указателя --> RightPtr < Str.size()
        for(int LeftPtr = 0, RightPtr = 0; RightPtr < Str.size(); ++RightPtr) { 

            for(; CharToExistingInSlidingWindow[Str[RightPtr]] == true; ++LeftPtr) {
                CharToExistingInSlidingWindow[Str[LeftPtr]] = false;
            } 

            CharToExistingInSlidingWindow[Str[RightPtr]] = true;
            // Теперь выполняется ивариант, что в SW  = {Str[LeftPtr], ..., Str[RightPtr]} лишь один уникальный символ
            // ввиду чего, обновляем ответ: 
            Length = max(Length, RightPtr - LeftPtr + 1);
        }

        return Length;
    }
};
