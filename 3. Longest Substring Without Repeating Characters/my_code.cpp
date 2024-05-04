class Solution {

private:
    const int POWER_ENCODING = 256;

public:
    int lengthOfLongestSubstring(string_view Str) {
        
        vector<bool> CharToExistingInSlidingWindow(POWER_ENCODING, false);

        int Length = 0;
        int Right = 0; // правый указатель поднимает флаг о сущест-и символа 

        // левый указатель опускает флаг о сущест-и символа 
        for(int Left = 0; Left < Str.size(); ++Left){ // сдвиг левого указателя
            
            // проверка на сдвиг правого указателя: необходимо выполнение услвоия "substring without repeating characters."
            for(;Right < Str.size() && CharToExistingInSlidingWindow[Str[Right]] == false;++Right){  // сдвиг правого указателя
                CharToExistingInSlidingWindow[Str[Right]] = true;  // обновляем информацию о окне после сдвига правого указателя               
            }

            Length = max(Length, Right - Left); // "find the length of the longest substring"

            assert(Left <= Right); // инваринат, который появляется при работе с думя указателями

            CharToExistingInSlidingWindow[Str[Left]] = false; // левый указатель сдвинулся, убираем информацию о нем из окна
        }

        return Length;

    }
};
